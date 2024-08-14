#include <iostream>
#include "list.h"
#include "vector.h"
using namespace std;

// 右值引用,完美转发,移动构造,移动赋值,decltype,default,delete,final,override学习;

void test1()
{
	initializer_list<int> il1 = { 1,2,3,4 };

	for (auto e : il1)
	{
		cout << e << " ";
	}
	cout << endl;

	auto il2 = { 1,2,3,4,5 };
	cout << typeid(il2).name() << endl;
}

#ifdef TEST1
// {}可以初始化一切
void test2()
{
	kozen::vector<int> v = { 1,2,3,4,5,6,21,43 };
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	kozen::list<int> lt = { 1,2,3,4,5,6,21,43 };
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	int arr1[3] = { 1 };
	int arr2[]{ 1,2,34,5 };
	using pint = int*;
	pint p1{ nullptr };

	struct X_Y
	{
		int _x;
		int _y;
	};

	X_Y xy = { 1,2 };

	pint arr3 = new int[3] { 1, 2, 4 };
	pint arr4 = new int(3);						// () -- 构造函数
	vector<int>* pv = new vector<int>(4, 2);	// () -- 构造函数
	delete pv;

	vector<int> v1{ 3,39 };		// {} -- 调用initializer_list构造函数
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	class Date
	{
	public:
		Date(int y, int m , int d)
			:_y(y),_m(m),_d(d)
		{}

	private:
		int _y;
		int _m;
		int _d;
	};

	Date d1(1, 2, 3);
	Date d2{ 2,3,4 };	// 默认构造



}

template<class T1, class T2>
void func1(const T1 x, const T2 y)
{
	decltype(x * y) XY;
	decltype(&x) px;
	cout << typeid(XY).name() << endl;
	cout << typeid(px).name() << endl;

}

void test_decltype()
{
	int a = 1;
	double b = 1.0;
	decltype(a * b) ab;			// 将返回值类型作为typedef的类型
	cout << typeid(ab).name() << endl;	//typeid(ab).name()	匿名对象,成员函数
	decltype(&a) pa;
	cout << typeid(pa).name() << endl;
	cout << typeid(int).name() << endl;

	func1(1, 'c');
	func1(10.2, 'c');

}

vector<vector<int>> vfunc()
{
	vector<vector<int>> vv(3, vector<int>(4, 1));
	cout << &(vv[0][0]) << endl;
	return vv;
}

// 左值引用和右值引用
void test_reference()
{
	int a = 1;
	int& ra1 = a;
	const int& ra2 = a;
	auto& ra3 = a;
	const auto& ra4 = a;
	const int& rc1 = 12;
	int* const& rp1 = &a;
	int* pa = &a;
	int*& rp2 = pa;


	int&& r1 = 1;
	int&& r2 = 2 + 1;
	int&& r3 = a + rc1;

	&r1;		// 用一块空间存储,可以取地址
	&r2;
	r1 = 3;		// 右值引用的属性改变为左值引用,可以修改,
	cout << r1 << endl;

	vector<vector<int>>&& rvv1 = vfunc();	// 移动构造,资源转移
	cout << &(rvv1[0][0]) << endl;
	auto&& rvv2 = vfunc();
	cout << &(rvv2[0][0]) << endl;

}
#endif

kozen::vector<int> myvfunc()
{
	kozen::vector<int> v(3,1);
	cout << &v[0] << endl;
	return v;
}

// 左值引用和右值引用
void test_reference2()
{
	kozen::vector<int>&& rv1 = myvfunc();
	cout << &rv1[0] << endl;

	kozen::vector<int>&& rv2(kozen::vector<int>(2,2));		//编译器优化了?
	kozen::vector<int>&& rv3 = kozen::vector<int>(2, 2);
	int&& r1 = int();

	auto&& r4 = make_pair(1, 1);
	int a = 1;
	int&& r5 = move(a);
}

#include <string>
class People
{
public:
	People(const string& s = "peter", const string& id = "123456")
		:_name(s)
	{
		_id = new char[10];
		char* cur = _id;
		for (char ch : id)
		{
			*cur++ = ch;
		}
		*cur = '\0';
	}	

	// 移动构造
	People(People&& p) noexcept
	{
		cout << "People(People&& p) -- 移动构造" << endl;
		_name.swap(p._name);
		::swap(_id, p._id);
	}

	// 拷贝构造
	People(const People& p) noexcept
	{
		cout << "People(People& p) -- 拷贝构造" << endl;
		People tmp(p._name, p._id);
		_name.swap(tmp._name);
		std::swap(_id, tmp._id);
	}

	// 移动赋值
	People& operator=(People&& p) noexcept
	{
		cout << "People& operator=(People&& p) -- 移动赋值" << endl;
		_name.swap(p._name);
		::swap(_id, p._id);
		return *this;
	}

	// 赋值
	People& operator=(People& p) noexcept
	{
		cout << "People& operator=(People& p) -- 赋值" << endl;
		People tmp(p._name, p._id);
		_name.swap(tmp._name);
		std::swap(_id, tmp._id);
		return *this;
	}

	// c++11 新增了移动构造和移动赋值两个默认构造函数

	~People()
	{
		delete[] _id;
	}


//private:
	string _name;
	char* _id = nullptr;
};

People funcPeo()
{
	People p("zhangde", "654321");
	People p2("zgde", "5121");
	cout << &p._id << endl;
	return p;
}

void test_ref3()
{
	People p1;
	People&& rp1 = People();
	People&& rp2 = funcPeo();
	cout << &rp2._id << endl;

	People p2(People("houzo", "46546"));

	People rp3 = funcPeo();
	cout << &rp3._id << endl;

	People p3("dada", "54654");
	p3 = funcPeo();

	People p4(funcPeo());
	People p5(move(p3));

	p5 = p2;

	People p6 = p5;
}


//std::forward 完美转发在传参的过程中保留对象原生类型属性
void Fun(int& x) { cout << "左值引用" << endl; }
void Fun(const int& x) { cout << "const 左值引用" << endl; }
void Fun(int&& x) { cout << "右值引用" << endl; }
void Fun(const int&& x) { cout << "const 右值引用" << endl; }
// 模板中的&&不代表右值引用，而是万能引用，其既能接收左值又能接收右值。
// 模板的万能引用只是提供了能够接收同时接收左值引用和右值引用的能力，
template<typename T>
void PerfectForward(T&& t)
{
	//Fun(t);
	// 但是引用类型的唯一作用就是限制了接收的类型，后续使用中都退化成了左值，
	// 我们希望能够在传递过程中保持它的左值或者右值的属性, 就需要用我们下面学习的完美转发
	Fun(forward<T>(t));
}

template<class Ty>
void PerfectForward2(Ty&& val)
{
	PerfectForward(forward<Ty>(val));	// 每一步都要完美转发
}

void test_forward()
{
	PerfectForward(10);           // 右值
	int a;
	PerfectForward(a);            // 左值
	PerfectForward(std::move(a)); // 右值
	const int b = 8;
	PerfectForward(b);      // const 左值
	PerfectForward(std::move(b)); // const 右值

	cout << "------------" << endl;
	PerfectForward2(std::move(b)); // const 右值

}

void test_list_PerfectForward()
{
	kozen::list<int> lt = { 1,2,3,4,5 };
	for (auto e : lt)
		cout << e << " ";
	cout << endl;

	lt = { 5,6,7,8,9,10 };
	for (auto e : lt)
		cout << e << " ";
	cout << endl;
	cout << "------------" << endl;

	kozen::list<int> lt2 = { 1,2,4,6,7 };
	cout << lt2.size() << endl;

	lt2 = lt;
	cout << lt.size() << endl;
	lt2 = move(lt);
	cout << lt.size() << endl;
	cout << "------------" << endl;

	kozen::list<People> lt3 = { {"wodesan", "13531"}, {"heozhe","13534"} };
	lt3.push_back(People());
	cout << "------------" << endl;

	People p1 = { "hangsan", "86464" };
	cout << p1._name << endl;
	cout << &p1._id << endl;
	lt3.push_back(p1);
	cout << &p1._id << endl;
	cout << p1._name << endl;
	lt3.push_back(move(p1));
	cout << &p1._id << endl;
	cout << p1._name.size() << endl;	// 资源转移
	cout << "------------" << endl;

	kozen::list<string> lt4;
	lt4.push_back("1324654");	// 隐士类型转化,生成临时string对象,资源转移
	lt4.push_back("846844");
	string str1 = "fajlaj";
	lt4.push_back(str1);		// 拷贝构造



	//kozen::vector<int> v = { 1,2,3,4,5 };
	//for (auto e : v)
	//	cout << e << " ";
	//cout << endl;

	//v = { 5,6,7,8,9,10 };
	//for (auto e : v)
	//	cout << e << " ";
	//cout << endl;

	//kozen::vector<int> v2 = { 1,2,3 };
	//v2 = move(v);			// 这里为什么无法辨别是哪一个operator= ?
	//						// 换为原始写法后又可以辨识,编译器bug? 
	//						//难道对于编译器,右值和普通对象没有函数名修饰区别
	//cout << v.size() << endl;
	//for (auto e : v2)
	//	cout << e << " ";
	//cout << endl;

	//v = { 1,2,3 };
	//kozen::vector<int> v3(move(v));
	//cout << v.size() << endl;

}

// 默认移动构造/移动赋值
class Move
{
public:
	// 不写赋值,拷贝,析构任意一个,编译器会自动生成默认移动构造/移动赋值
	// 内置类型直接拷贝,自定义类型调用其移动语义(如果有)

	//Move() { cout << "Move()" << endl; };

	//~Move() {};
	Move() = default;
	//Move(const Move&) = default;	// 强制生成默认
	//Move(Move&&) = default;		// 强制生成默认, 有类型就可以,写不写参数都行
	Move& operator=(const Move&) = default;
	Move& operator=(Move&&) = default;
	Move* operator&() = delete;		// 取消默认生成

	Move(const Move& m)
	{
		cout << "Move(const Move&)" << endl;
		_s = m._s;
	}

	Move(Move&& m)
		//:_s(m._s)
		:_s(forward<string>(m._s))
	{
		cout << "Move(Move&&) -- 移动语义" << endl;
	}


public:
	string _s = "zhnagsan";
};

void test_ref4()
{
	kozen::list<Move> lt;
	lt.push_back(Move());
	Move m1;
	lt.push_back(m1);
	cout << m1._s << endl;
	lt.push_back(move(m1));
	cout << m1._s.size() << endl;

	Move m2;
	m1 = m2;
	cout << m1._s << endl;
	cout << m2._s << endl;
	m1 = move(m2);
	cout << m1._s << endl;
	cout << m2._s.size() << endl;
	//&m1;
}

//class Basic final		//final 修饰类,不能被继承
class Basic
{
public:
	virtual void func1() final	//final 修饰修函数,不能被重写
	{}

	//virtual void func2() = 0	// 抽象类(有纯虚函数)不能实例化
	virtual void func2() 
	{
		cout << "virtual void func2() = 0 -- 纯虚函数" << endl;
	}

	int _b;
};

//class Derive final : public Basic
//class Derive : virtual public Basic
//class Derive final : virtual public Basic
class Derive : public Basic
{
public:
	//virtual void func1()
	//{}

	//virtual void func2() final override	// 强制检测是否重写&不能被子类重写
	virtual void func2() override	// 强制检测是否重写
	{
		cout << "virtual void func2() -- 重写" << endl;
	}

	int _d;
};



void test_final_override()
{
	Derive d1;
	d1.func2();
	Basic& rb = d1;
	rb.func2();
	Basic b1;
	b1.func2();

}


//int main()
//{
//	//test2();
//	//test_decltype();
//	//test_reference2();
//
//	//test_ref3();
//	//test_forward();
//	//test_list_PerfectForward();
//	//test_ref4();
//	test_final_override();
//
//
//
//	return 0;
//}
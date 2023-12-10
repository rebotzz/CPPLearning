#include <iostream>
#include "list.h"
#include "vector.h"
using namespace std;

// ��ֵ����,����ת��,�ƶ�����,�ƶ���ֵ,decltype,default,delete,final,overrideѧϰ;

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
// {}���Գ�ʼ��һ��
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
	pint arr4 = new int(3);						// () -- ���캯��
	vector<int>* pv = new vector<int>(4, 2);	// () -- ���캯��
	delete pv;

	vector<int> v1{ 3,39 };		// {} -- ����initializer_list���캯��
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
	Date d2{ 2,3,4 };	// Ĭ�Ϲ���



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
	decltype(a * b) ab;			// ������ֵ������Ϊtypedef������
	cout << typeid(ab).name() << endl;	//typeid(ab).name()	��������,��Ա����
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

// ��ֵ���ú���ֵ����
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

	&r1;		// ��һ��ռ�洢,����ȡ��ַ
	&r2;
	r1 = 3;		// ��ֵ���õ����Ըı�Ϊ��ֵ����,�����޸�,
	cout << r1 << endl;

	vector<vector<int>>&& rvv1 = vfunc();	// �ƶ�����,��Դת��
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

// ��ֵ���ú���ֵ����
void test_reference2()
{
	kozen::vector<int>&& rv1 = myvfunc();
	cout << &rv1[0] << endl;

	kozen::vector<int>&& rv2(kozen::vector<int>(2,2));		//�������Ż���?
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

	// �ƶ�����
	People(People&& p) noexcept
	{
		cout << "People(People&& p) -- �ƶ�����" << endl;
		_name.swap(p._name);
		::swap(_id, p._id);
	}

	// ��������
	People(const People& p) noexcept
	{
		cout << "People(People& p) -- ��������" << endl;
		People tmp(p._name, p._id);
		_name.swap(tmp._name);
		std::swap(_id, tmp._id);
	}

	// �ƶ���ֵ
	People& operator=(People&& p) noexcept
	{
		cout << "People& operator=(People&& p) -- �ƶ���ֵ" << endl;
		_name.swap(p._name);
		::swap(_id, p._id);
		return *this;
	}

	// ��ֵ
	People& operator=(People& p) noexcept
	{
		cout << "People& operator=(People& p) -- ��ֵ" << endl;
		People tmp(p._name, p._id);
		_name.swap(tmp._name);
		std::swap(_id, tmp._id);
		return *this;
	}

	// c++11 �������ƶ�������ƶ���ֵ����Ĭ�Ϲ��캯��

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


//std::forward ����ת���ڴ��εĹ����б�������ԭ����������
void Fun(int& x) { cout << "��ֵ����" << endl; }
void Fun(const int& x) { cout << "const ��ֵ����" << endl; }
void Fun(int&& x) { cout << "��ֵ����" << endl; }
void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }
// ģ���е�&&��������ֵ���ã������������ã�����ܽ�����ֵ���ܽ�����ֵ��
// ģ�����������ֻ���ṩ���ܹ�����ͬʱ������ֵ���ú���ֵ���õ�������
template<typename T>
void PerfectForward(T&& t)
{
	//Fun(t);
	// �����������͵�Ψһ���þ��������˽��յ����ͣ�����ʹ���ж��˻�������ֵ��
	// ����ϣ���ܹ��ڴ��ݹ����б���������ֵ������ֵ������, ����Ҫ����������ѧϰ������ת��
	Fun(forward<T>(t));
}

template<class Ty>
void PerfectForward2(Ty&& val)
{
	PerfectForward(forward<Ty>(val));	// ÿһ����Ҫ����ת��
}

void test_forward()
{
	PerfectForward(10);           // ��ֵ
	int a;
	PerfectForward(a);            // ��ֵ
	PerfectForward(std::move(a)); // ��ֵ
	const int b = 8;
	PerfectForward(b);      // const ��ֵ
	PerfectForward(std::move(b)); // const ��ֵ

	cout << "------------" << endl;
	PerfectForward2(std::move(b)); // const ��ֵ

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
	cout << p1._name.size() << endl;	// ��Դת��
	cout << "------------" << endl;

	kozen::list<string> lt4;
	lt4.push_back("1324654");	// ��ʿ����ת��,������ʱstring����,��Դת��
	lt4.push_back("846844");
	string str1 = "fajlaj";
	lt4.push_back(str1);		// ��������



	//kozen::vector<int> v = { 1,2,3,4,5 };
	//for (auto e : v)
	//	cout << e << " ";
	//cout << endl;

	//v = { 5,6,7,8,9,10 };
	//for (auto e : v)
	//	cout << e << " ";
	//cout << endl;

	//kozen::vector<int> v2 = { 1,2,3 };
	//v2 = move(v);			// ����Ϊʲô�޷��������һ��operator= ?
	//						// ��Ϊԭʼд�����ֿ��Ա�ʶ,������bug? 
	//						//�ѵ����ڱ�����,��ֵ����ͨ����û�к�������������
	//cout << v.size() << endl;
	//for (auto e : v2)
	//	cout << e << " ";
	//cout << endl;

	//v = { 1,2,3 };
	//kozen::vector<int> v3(move(v));
	//cout << v.size() << endl;

}

// Ĭ���ƶ�����/�ƶ���ֵ
class Move
{
public:
	// ��д��ֵ,����,��������һ��,���������Զ�����Ĭ���ƶ�����/�ƶ���ֵ
	// ��������ֱ�ӿ���,�Զ������͵������ƶ�����(�����)

	//Move() { cout << "Move()" << endl; };

	//~Move() {};
	Move() = default;
	//Move(const Move&) = default;	// ǿ������Ĭ��
	//Move(Move&&) = default;		// ǿ������Ĭ��, �����;Ϳ���,д��д��������
	Move& operator=(const Move&) = default;
	Move& operator=(Move&&) = default;
	Move* operator&() = delete;		// ȡ��Ĭ������

	Move(const Move& m)
	{
		cout << "Move(const Move&)" << endl;
		_s = m._s;
	}

	Move(Move&& m)
		//:_s(m._s)
		:_s(forward<string>(m._s))
	{
		cout << "Move(Move&&) -- �ƶ�����" << endl;
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

//class Basic final		//final ������,���ܱ��̳�
class Basic
{
public:
	virtual void func1() final	//final �����޺���,���ܱ���д
	{}

	//virtual void func2() = 0	// ������(�д��麯��)����ʵ����
	virtual void func2() 
	{
		cout << "virtual void func2() = 0 -- ���麯��" << endl;
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

	//virtual void func2() final override	// ǿ�Ƽ���Ƿ���д&���ܱ�������д
	virtual void func2() override	// ǿ�Ƽ���Ƿ���д
	{
		cout << "virtual void func2() -- ��д" << endl;
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
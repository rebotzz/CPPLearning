//#include <iostream>
//
//using namespace std;
//
////模板练习
//
//inline void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//template<typename T>
//inline void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//template<class T>
//inline T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//
//template<class T,class K>
//inline T Add(const T& x, const K& y)
//{
//	return x + y;
//}


//int main()
//{
//	int a = 2, b = 3;
//	Swap(a, b);
//	double fa = 2.5, fb = 3.7;
//	Swap(fa, fb);
//	char ca = 'y', cb = 'n';
//	Swap(ca, cb);
//
//	swap(a, b);		//库里面的
//
//	cout << Add(a, b) << endl;
//	cout << Add(fa, fb) << endl;
//	cout << (char)(Add(ca, cb) + 60) << endl;		//整形提升,变负数了
//	cout << (int)Add(ca, cb) << endl;
//	//1110 0111
//	//最小处理单元:整形提升到int, 按符号位补位
//	//1111 1111 1111 1111 1111 1111 1110 0111	补码	负数
//	//1111 1111 1111 1111 1111 1111 1110 0110	反码
//	//0000 0000 0000 0000 0000 0000 0001 1001	原码
//
//	cout << Add('1', 'A') << endl;
//	cout << (int)'1' << endl;
//	cout << (int)'A' << endl;
//	cout << Add(a, (int)fa) << endl;		//强制类型转化
//	cout << Add<double>(a, fa) << endl;		//显示实例化
//	cout << Add(a, fa) << endl;
//
//	return 0;
//}
//#include <iostream>
//
//using namespace std;
//
////ģ����ϰ
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
//	swap(a, b);		//�������
//
//	cout << Add(a, b) << endl;
//	cout << Add(fa, fb) << endl;
//	cout << (char)(Add(ca, cb) + 60) << endl;		//��������,�为����
//	cout << (int)Add(ca, cb) << endl;
//	//1110 0111
//	//��С����Ԫ:����������int, ������λ��λ
//	//1111 1111 1111 1111 1111 1111 1110 0111	����	����
//	//1111 1111 1111 1111 1111 1111 1110 0110	����
//	//0000 0000 0000 0000 0000 0000 0001 1001	ԭ��
//
//	cout << Add('1', 'A') << endl;
//	cout << (int)'1' << endl;
//	cout << (int)'A' << endl;
//	cout << Add(a, (int)fa) << endl;		//ǿ������ת��
//	cout << Add<double>(a, fa) << endl;		//��ʾʵ����
//	cout << Add(a, fa) << endl;
//
//	return 0;
//}
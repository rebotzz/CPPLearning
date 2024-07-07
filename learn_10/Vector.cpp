//#pragma once
//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//
////����,�Զ������Ͷ�̬˳���
//template<class T>
//class Vector
//{
//public:
//	Vector(size_t capacity = 2)
//		:_pData(new T[capacity])
//		, _size(0)
//		, _capacity(capacity)
//	{}
//	~Vector();
//
//	//β��
//	void PushBack(const T& x)
//	{
//		CheckCapacity();
//		_pData[_size++] = x;
//	}
//	//βɾ
//	void PopBack()
//	{
//		assert(_size > 0);
//		_size--;
//	}
//	//[]����
//	T operator[](int i)
//	{
//		return _pData[i];	//_pData��T����ָ��,_pData[i] ==> *(_pData + i)
//	}
//	//=����
//	//���...
//
//	//���,����
//	void CheckCapacity()
//	{
//		if (_capacity == _size)
//		{
//			_capacity *= 2;
//			T* tmp = new T[_capacity];
//			//����֮ǰ��
//			for (int i = 0; i < _size; i++)
//			{
//				tmp[i] = _pData[i];
//			}
//			//���쳣��ʱûѧ...
//			delete[] _pData;
//			_pData = tmp;
//			//delete[] tmp;	//����delete[],�����¿��ٵĿռ�
//			tmp = nullptr;
//		}
//	}
//
//	//��С
//	int Size()
//	{
//		return _size;
//	}
//	//�п�
//	bool Empty()
//	{
//		return _size == 0;
//	}
//
//private:
//	T* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//
//template<class T>
//Vector<T>::~Vector()
//{
//	if (_pData)
//	{
//		delete[] _pData;
//		_capacity = _size = 0;
//	}
//}
//
//////ȫ��,<<����
////template<class T>
////ostream& operator<<(const ostream& out, const T& x)
////{
////	//...����,�������͵������õ�,�Զ������͵��ø�����<<����
////	//���ﲻ����ģ��...
////}
//
//class Time
//{
//	friend ostream& operator<<(ostream& out, const Time& t);	
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{}
//	Time(const Time& h)
//	{
//		_hour = h._hour;
//	}
//
//	Time& operator=(const Time& h)
//	{
//		if (this != &h)
//		{
//			_hour = h._hour;
//		}
//		return *this;
//	}
//
//private:
//	int _hour = 0;
//};
//
//ostream& operator<<(ostream& out, const Time& t)
//{
//	out << t._hour;
//	return out;
//}
////
////int main()
////{
////	//Vector<Time> arr(4);
////	//Time h(12);
////	//arr.PushBack(h);
////	//arr.PushBack(2);
////	//arr.PushBack(3);	//��ʽ����ת��
////	//arr.PushBack(4);
////	//arr.PushBack(5);
////	//for (int i = 0; i < arr.Size(); ++i)
////	//{
////	//	cout << arr[i] << " ";
////	//}
////	//cout << endl;
////
////	//while (!arr.Empty())
////	//{
////	//	arr.PopBack();
////	//}
////	//
////	//for (int i = 0; i < 3; ++i)
////	//{
////	//	arr.PushBack(i);
////	//}
////	//for (int i = 0; i < arr.Size(); ++i)
////	//{
////	//	cout << arr[i] << " ";
////	//}
////	//cout << endl;
////
////	//Time h[4];		//���ַ���C�﷨,�����h��Time*����ָ��,��������Time�������������[]
////	//for (const auto& e : h)
////	//{
////	//	cout << e << " ";
////	//}
////	//cout << endl;
////
////	return 0;
////}
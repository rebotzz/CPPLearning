//#pragma once
//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//
////容器,自定义类型动态顺序表
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
//	//尾插
//	void PushBack(const T& x)
//	{
//		CheckCapacity();
//		_pData[_size++] = x;
//	}
//	//尾删
//	void PopBack()
//	{
//		assert(_size > 0);
//		_size--;
//	}
//	//[]重载
//	T operator[](int i)
//	{
//		return _pData[i];	//_pData是T类型指针,_pData[i] ==> *(_pData + i)
//	}
//	//=重载
//	//深拷贝...
//
//	//检查,扩容
//	void CheckCapacity()
//	{
//		if (_capacity == _size)
//		{
//			_capacity *= 2;
//			T* tmp = new T[_capacity];
//			//拷贝之前的
//			for (int i = 0; i < _size; i++)
//			{
//				tmp[i] = _pData[i];
//			}
//			//抛异常暂时没学...
//			delete[] _pData;
//			_pData = tmp;
//			//delete[] tmp;	//不能delete[],这是新开辟的空间
//			tmp = nullptr;
//		}
//	}
//
//	//大小
//	int Size()
//	{
//		return _size;
//	}
//	//判空
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
//////全局,<<重载
////template<class T>
////ostream& operator<<(const ostream& out, const T& x)
////{
////	//...不用,内置类型调用内置的,自定义类型调用该类型<<重载
////	//这里不能用模板...
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
////	//arr.PushBack(3);	//隐式类型转化
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
////	//Time h[4];		//这种符合C语法,这里的h是Time*数组指针,所以这里Time不用运算符重载[]
////	//for (const auto& e : h)
////	//{
////	//	cout << e << " ";
////	//}
////	//cout << endl;
////
////	return 0;
////}
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// 智能指针学习
// 1.RAII思想	利用构造析构实现资源管理
// 2.模仿指针行为
//
namespace kozen
{
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			delete _ptr;
			_ptr = nullptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()
		{
			return _ptr;
		}

		// 不支持拷贝
		unique_ptr(const unique_ptr<T>& ptr) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& ptr) = delete;
	private:
		T* _ptr;
	};

	void test_unique()
	{
		unique_ptr<int> up1(new int(3));
		cout << up1.get() << endl;
		cout << *up1 << endl;
		*up1 = 4;
		cout << *up1 << endl;

		//unique_ptr<int> copy(up1);

		struct A
		{
			int _a = 10;
		};
		unique_ptr<A> up2 = new A;
		cout << "struct A" << endl;
		cout << up2->_a << endl;
	}



	//////////////////////////////////////////////////////////////////
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _mtx(new std::mutex)
		{}

		~shared_ptr()
		{
			release();
		}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)	//别写错，不是:
			, _mtx(sp._mtx)
		{
			addCount();
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//if (&sp == this)
			if (_ptr == sp._ptr)	// 管理同一份资源时
			{
				return *this;
			}
			// 处理原有资源
			release();

			// 指向新资源
			_ptr = sp._ptr;
			_pcount = sp._pcount;
			_mtx = sp._mtx;
			addCount();

			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()
		{
			return _ptr;
		}

		int use_count()
		{
			return *_pcount;
		}

	private:
		void release()
		{
			//lock_guard<mutex> lock(*_mtx);
			_mtx->lock();
			if (0 == --(*_pcount))
			{
				cout << "delete: " << _ptr << endl;
				delete _ptr;
				delete _pcount;
				_ptr = nullptr;
				_pcount = nullptr;

				_mtx->unlock();	
				delete _mtx;	// delete mutex ???
			}
			else
			{	// 小心死锁
				_mtx->unlock();
			}
		}

		void addCount()
		{
			lock_guard<mutex> lock(*_mtx);
			++(*_pcount);
		}

	private:
		T* _ptr;
		int* _pcount;	// 引用计数，防止重复delete
		std::mutex* _mtx;	// 多线程时保护资源
	};


	void test_shared()
	{
		shared_ptr<int> sp1(new int(2));
		shared_ptr<int> sp2(sp1);
		shared_ptr<int> sp3(sp2);

		shared_ptr<int> sp4(new int(3));
		//sp4 = sp1;
		sp1 = sp4;
	}

	void test_shared_safe()
	{
		shared_ptr<int> sp = new int(10);
		cout << sp.get() << endl;
		int n = 60000;
		auto func = [&sp, n]() {
			cout <<"thread: " << this_thread::get_id() << endl;
			for (int i = 0; i < n; ++i)
			{
				shared_ptr<int> copy(sp);
			}
			};
		thread t1(func);
		thread t2(func);
		
		t1.join();
		t2.join();
		cout << sp.get() << endl;
		cout << "count: " << sp.use_count() << endl;
	}

}

//int main()
//{
//	cout << "test" << endl;
//
//	//kozen::test_unique();
//	try
//	{
//		kozen::test_shared_safe();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}
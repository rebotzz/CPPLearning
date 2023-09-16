// string::begin/end
#include <iostream>
//#include <string>
using namespace std;

//int main()
//{
//    std::string str("Test string");
//    for (std::string::iterator it = str.begin(); it != str.end(); ++it)
//        std::cout << *it;
//    std::cout << '\n';
//
//    return 0;
//}


int main()
{
	string s1 = "123465";
	cout << s1 << endl;
	s1 += "fsas";
	cout << s1 << endl;

	string::iterator it = s1.begin();		//it是一个迭代器指针,
	for (auto i = it; i < s1.end(); ++i)
	{
		cout << *i << " ";
		*i = 's';
	}
	cout << endl;

	for (auto it = s1.begin(); it != s1.end(); ++it)
	{
		cout << *it;
	}
	cout << endl;

	const string s2("sajfklajsf23r23");
	for (auto& e : s2)
	{
		cout << e;
	}
	cout << endl;

	string::const_iterator it2 = s2.cbegin();
	for (it2; it2 != s2.cend(); ++it2)
	{
		cout << *it2;
	}
	cout << endl;

	cout << "---------------------------------------" << endl;

	string s3 = "1234566789abc		1";		//Tab和空格间距不一样,初步怀疑是编码的问题;
	for (auto e : s3)
	{
		cout << e;
	}
	cout << endl;

	//string::reverse_iterator it = s3.rbegin();
	for (auto it = s3.rbegin(); it != s3.rend(); ++it)
	{
		cout << *it;
	}
	cout << endl;
	cout << "size of s1 is :" << s1.size() << endl;
	cout << "size of s2 is :" << s2.size() << endl;
	cout << "size of s3 is :" << s3.size() << endl;
	s1 = "123456";
	for (const auto& e : s1)
	{
		cout << e;
	}
	cout << endl;
	cout << "size of s1 is :" << s1.size() << endl;
	cout << "length of s1 is :" << s1.length() << endl;
	cout << "max_size is " << s1.max_size() << endl;
	cout << s1 << endl;
	cout << string("unname object") << endl;

	s1 = "123456789";
	s1.resize(6);
	cout << s1 << endl;
	cout << "capacity of s1 is " << s1.capacity() << endl;
	s1.resize(10, 'c');
	cout << s1 << ";size of s1 is " << s1.size() << endl;
	cout << "capacity of s1 is " << s1.capacity() << endl;
	s1.resize(16);
	cout << s1 << ";size of s1 is " << s1.size() << endl;
	cout << "capacity of s1 is " << s1.capacity() << endl;
	s1.resize(6);
	cout << s1 << ";size of s1 is " << s1.size() << endl;
	cout << "capacity of s1 is " << s1.capacity() << endl;
	s1.reserve(s1.size());
	cout << s1 << ";size of s1 is " << s1.size() << endl;
	cout << "capacity of s1 is " << s1.capacity() << endl;

	s1.reserve(2);
	cout << s1 << endl;
	cout << s1 << ";size of s1 is " << s1.size() << endl;
	cout << "capacity of s1 is " << s1.capacity() << endl;

	s1.reserve(20);
	cout << s1 << endl;
	cout << s1 << ";size of s1 is " << s1.size() << endl;
	cout << "capacity of s1 is " << s1.capacity() << endl;
	cout << "----------------------------" << endl;

	s1.clear();
	cout << s1 << endl;
	cout << "size of s1 is " << s1.size() << endl;
	if (s1.empty())
	{
		cout << "s1 is empty" << endl;
	}

	s1 += "9874431513aaa";
	cout << s1 << ";size of s1 is " << s1.size() << endl;
	cout << "capacity of s1 is " << s1.capacity() << endl;
	s1.shrink_to_fit();
	cout << s1 << ";size of s1 is " << s1.size() << endl;
	cout << "capacity of s1 is " << s1.capacity() << endl;

	for (int i = 0; i <= s1.size(); ++i)
	{
		cout << ++s1[i] << " ";
	}
	cout << endl;

	cout << s1.at(2) << endl;
	cout << s1.back() << endl;
	s1.back() = '!';
	cout << s1 << endl;
	s1.front() = 'M';
	cout << s1 << endl;

	for (int i = 1; i <= s1.size(); i += 2)
	{
		s1.insert(i, 1, ' ');
	}
	cout << s1 << endl;

	cout << s1.insert(3, "Hello") << endl;
	//cout << s1 << endl;
	cout << s1.erase(3, 5) << endl;
	cout << s1.replace(3, 5, "Xxx  ") << endl;
	cout << s1.replace(3, 5, 5, 'z') << endl;
	cout << "s1 : " << s1 << endl;
	cout << "s3 : " << s3 << endl;
	s1.swap(s3);			//通过改变指针指向实现,效率高;全局的swap需要交换内容,效率低
	cout << "swap:" << endl;
	cout << "s1 : " << s1 << endl;
	cout << "s3 : " << s3 << endl;

	s1.pop_back();
	cout << s1 << endl;
	//const char* str = new char[s1.size() + 1];	//不能这样,str = s1.c_str()会丢失空间的指针
	const char* str = s1.c_str();		
	cout << "str: " << str << endl;
	//delete[] str;

	string s4 = "1";
	cout << s4.size() << endl;

	return 0;
}
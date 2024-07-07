<<<<<<< HEAD
# week_9
第9周学习:C++和Linux
*********************
C++:
1.日期类实现:运算符重载,构造,析构,拷贝构造,赋值重载;
函数复用
2.日期类完善:<<,>>运算符重载,友元函数/类,const修饰成员函数(*this);
static静态成员,静态成员函数,初始化列表(成员变量定义位置),内置类;
匿名对象,(变长数组:>待学习),隐式类型转化,explicit取消隐式类型转化
编译器优化:例如,函数值返回的临时变量有接受者,优化掉临时变量;
3.cpp链表实现
4.Oj作业练习
5.内存管理学习,malloc free ; new delete ; new [] delete[] ; 定位new,内存池;
6.模板,template<class T>;
7.STL: string学习
8.数据结构初阶考试,这让我认识到笔记很重要,遗忘中重复,重复中升华;
可以不用堆很多笔记在一次写完,明白一个知识点就写一个知识点的笔记,之后就是整理;
9.计数排序






**********************
Linux:
1.shell外壳程序,权限:chmod,chown,chgrp,文件类型,umask,粘滞位 +t
2.vim使用
3.gcc g++ 动态/静态库 .so/.a .dll/.lib -static
4.make Makefile 依赖关系/方法
5.yum,git使用
6.进程,操作系统
=======
# week_10
第10周的学习
**********************
1.模板学习template<typename T>  template<class T>
2.STL学习,string		
3.string练习题:字符串相加/相乘;第一个只出现一次字符串;翻转字符串1/2/3; 
 string模拟实现1/2 ; 注意if()不同类型比较类型转化问题,eg:size_t > int ==> size_t
 string模拟实现1/2/3; end = _size + 1; if(pos < end);可以解决当pos=0,end越界的问题,类型size_t
 s.get()可以读取缓冲区' '和'\0';但是>>不能;cout<<s可以答应'\0'后面的字符,C_str不能;
不要轻易缩容,缩容代价比较大
************************************************
4.vector学习	
vector学习1 使用,模拟实现,迭代器失效问题
vector学习1/2 模拟实现,vector<vector<int>>,深浅拷贝问题
vector学习1/2/3 模拟实现
list学习1
list学习1/2 模拟实现	迭代器实现,对原生指针的封装,实现想要的运算符重载功能
stack/queue学习1  适配器

**********************************
vector,list增加了反向迭代器适配器实现,但是有bug:const_reverse_iterator有问题,原因未知
debug:	//原因:reverse_iterator类型已经被重定义了,现在是reverse_iterator<iterator, T&, T*>,所以使用模板报错
	//修改:将reverse_iterator类名改为Reverse_iterator
	//const对象返回const_iterator,所以需要用const_iterator接受
	//总结:模板类名和tepedef后的类型名最好不同,否则分不清容易弄错
	typedef Reverse_iterator<const_iterator,const T&,const T*> const_reverse_iterator;


********************************
linux笔记整理 1.基础指令
linux虚拟地址空间学习,进程控制学习
退出码,信号学习
fork()+wait()
进程退出三种情况:1.进程跑完,结果正确(退出码0).2.进程跑完,结果错误(退出码非0,对应错误原因).3.进程崩溃.(退出码无效,程序被操作系统利用信号Kill,有退出信号);
>>>>>>> w10/main

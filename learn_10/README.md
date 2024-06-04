# week_10
第10周的学习
- 1.模板学习template<typename T>  template<class T>
- 2.STL学习,string		
- 3.string练习题:
```
字符串相加/相乘;第一个只出现一次字符串;翻转字符串1/2/3; 
 string模拟实现1/2 ; 注意if()不同类型比较类型转化问题,eg:size_t > int ==> size_t
 string模拟实现1/2/3; end = _size + 1; if(pos < end);可以解决当pos=0,end越界的问题,类型size_t
 s.get()可以读取缓冲区' '和'\0';但是>>不能;cout<<s可以答应'\0'后面的字符,C_str不能;
不要轻易缩容,缩容代价比较大
```

- 4.vector学习	
```
vector学习1 使用,模拟实现,迭代器失效问题
vector学习1/2 模拟实现,vector<vector<int>>,深浅拷贝问题
vector学习1/2/3 模拟实现
list学习1
list学习1/2 模拟实现	迭代器实现,对原生指针的封装,实现想要的运算符重载功能
stack/queue学习1  适配器

vector,list增加了反向迭代器适配器实现,但是有bug:const_reverse_iterator有问题,原因未知
debug:	
原因:reverse_iterator类型已经被重定义了,现在是reverse_iterator<iterator, T&, T*>,所以使用模板报错
修改:将reverse_iterator类名改为Reverse_iterator
const对象返回const_iterator,所以需要用const_iterator接受
总结:模板类名和tepedef后的类型名最好不同,否则分不清容易弄错
typedef Reverse_iterator<const_iterator,const T&,const T*> const_reverse_iterator;
```

### linux笔记整理 
- 1.基础指令
- 2.linux虚拟地址空间学习,进程控制学习
退出码,信号学习
fork()+wait()
- 进程退出三种情况:
```
1.进程跑完,结果正确(退出码0).
2.进程跑完,结果错误(退出码非0,对应错误原因).
3.进程崩溃.(退出码无效,程序被操作系统利用信号Kill,有退出信号);
```

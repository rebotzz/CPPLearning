#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

void test1()
{
	Date d1(2023, 8, 31);
	Date d2;
	d2 = d1;	//d2.operator=(d1);	this指针隐藏
	(++d2).print();
	//(d2++).print();
	(--d2).print();
	//(d2--).print();

	//cout << (d1 >= d2) << endl;


	(d2 + 50).print();
	(d2 + 500).print();
	(d2 + 5000).print();
	(d2 + 50000).print();

	cout << endl;
	d2 -= 50;
	d2.print();
	d2 -= 500;
	d2.print();
	d2 -= 5000;
	d2.print();
	d2 -= 50000;
	d2.print();
	cout << endl;

	d2 = d1;
	(d2 - 50).print();
	(d2 - 500).print();
	(d2 - 5000).print();
	(d2 - 50000).print();
	cout << endl;

	d2 += 5087640;
	d2.print();
	cout << (d1 - d2) << endl;

	cout << endl;
	Date d3(1999, 3, 7);
	cout << (d1 - d3) << endl;
	d3.operator+=(1);
	d3.print();
}

void test2()
{
	Date d1(2023, 2, 28);

	(d1 + -3).print();
	(d1 - -3).print();

}


//void test3()
//{
//	typedef char* pstring;
//
//	const pstring p1;    // 编译成功还是失败？	err,常量必须初始化
//	const pstring* p2;
//}

void test4()
{

	Date d1(2023, 5, 7);
	cout << d1;
	cin >> d1;
	cout << d1;
	Date* pd1 = &d1;
	int* tmp = (int*)&d1;
	*tmp = 100;	//private只在编译阶段限制访问,在内存中没有限制访问
	*pd1 = 123;	//隐式类型转化,构造(123构造一个临时Date对象) + 赋值重载 (临时对象赋值d1)
	cout << d1;

	Date d2 = d1 + 1231;
	cout << d1 << d2;
	cin >> d1 >> d2;
	cout << d1 << d2;

}

//菜单
void meun()
{
	printf("********************       日期计算器       ******************\n");
	printf("**************** 1.日期+/-天数   2.日期 - 日期  **************\n");
	printf("**************** 0.退出                         **************\n");
	printf("**************************************************************\n");

}

void test5()
{
	int input = 1;
	Date d;
	Date d1;
	int day;
	//周几
	char week[][7] = { "周一","周二","周三" ,"周四" ,"周五" ,"周六","周天" };
	int num = 0;
	Date d0(1, 1, 1);

	//注意,这里程序没有输入0正常退出,进程还在内存中, 处于堵塞状态,占用内存  关闭窗口能关掉进程吗??前台进程
	do
	{
		//菜单
		meun();
		cout << "请输入选择:>";
		cin >> input;
		switch (input)
		{
		case EXIT:
			cout << "退出程序.";
			break;
		case ADD_SUB_DAY:
			cout << "请输入日期和要加减的天数(+/-),减(-)输入负数:>";
			cin >> d >> day;
			d += day;
			num = (d - d0) % 7;
			//cout << "tmp:"<<tmp<<"   w:" << wday << endl;
			cout << "结果:" << d << " " << week[num] << endl;
			break;
		case SUB_DATE:
			cout << "请输入要相减的日期:>";
			cin >> d >> d1;
			cout << "结果:" << (d - d1) << "天" << endl;
		}

	} while (input);
}

int main()
{
	test5();

	//Date d(2023, 9, 7);
	//Date d0(1, 1, 1);
	//d.operator<<(cout) << endl;
	//cout << (d - d0) << endl;
	//d += 1;
	//cout << (d - d0) << endl;


	return 0;
}
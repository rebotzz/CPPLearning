#define _CRT_SECURE_NO_WARNINGS

//结构体学习
//
//#include <stdio.h>
//
//int main()
//{
//	struct student
//	{
//		int num;
//		char name[20];//可以是数组
//		char sex;
//		int age;
//	}stu1 = { 1000,"张三",'F',17 };
//	
//	struct student stu2 = { 1001,"李敏",'M',16 };
//	struct student* p = &stu2;
//	printf("num: %d\tname:%s\tsex:%c\tage:%d\n", stu1.num, stu1.name, stu1.sex, stu1.age);
//	printf("num: %d\tname:%s\tsex:%c\tage:%d\n", (*p).num, (*p).name, (*p).sex, (*p).age);
//	printf("num: %d\tname:%s\tsex:%c\tage:%d\n", p->num,p->name,p->sex,p->age);
//	stu1.age = 19;
//	p->sex = 'F';
//	struct student stu[3] = { stu1,stu2,{1003,"黄衣之主",'?',10015} };
//	struct student* pstu = stu;//数组名 = 数组首元素地址
//	for (pstu = stu; pstu < stu + 3; pstu++) //stu + 3 到数组第三位元素下一位的地址
//	{
//		printf("num: %d\tname:%s\tsex:%c\tage:%d\n", pstu->num, pstu->name, pstu->sex, pstu->age);
//
//	}
//
//	struct book
//	{
//		int num;
//		char name[40];
//		struct student stu;//嵌套定义
//
//	}work[3] = { {01,"<<奇怪谈>>",stu[0]},{02,"<<每天一个摸鱼小技巧>>",stu[1]},{03,"<<剧本创作心得>>",stu[2]}};
//	struct book* pb = work;
//	int i = 0;
//	for (pb = work, i = 0; pb < work + 3 && i < 3; pb++, i++)
//	{
//		printf("编号:%d\t书名:%s\n", pb->num, pb->name);
//		printf("作者信息->  num: %d\tname:%s\tsex:%c\tage:%d\n", stu[i].num,stu[i].name,stu[i].sex,stu[i].age);
//	}
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS

//�ṹ��ѧϰ
//
//#include <stdio.h>
//
//int main()
//{
//	struct student
//	{
//		int num;
//		char name[20];//����������
//		char sex;
//		int age;
//	}stu1 = { 1000,"����",'F',17 };
//	
//	struct student stu2 = { 1001,"����",'M',16 };
//	struct student* p = &stu2;
//	printf("num: %d\tname:%s\tsex:%c\tage:%d\n", stu1.num, stu1.name, stu1.sex, stu1.age);
//	printf("num: %d\tname:%s\tsex:%c\tage:%d\n", (*p).num, (*p).name, (*p).sex, (*p).age);
//	printf("num: %d\tname:%s\tsex:%c\tage:%d\n", p->num,p->name,p->sex,p->age);
//	stu1.age = 19;
//	p->sex = 'F';
//	struct student stu[3] = { stu1,stu2,{1003,"����֮��",'?',10015} };
//	struct student* pstu = stu;//������ = ������Ԫ�ص�ַ
//	for (pstu = stu; pstu < stu + 3; pstu++) //stu + 3 ���������λԪ����һλ�ĵ�ַ
//	{
//		printf("num: %d\tname:%s\tsex:%c\tage:%d\n", pstu->num, pstu->name, pstu->sex, pstu->age);
//
//	}
//
//	struct book
//	{
//		int num;
//		char name[40];
//		struct student stu;//Ƕ�׶���
//
//	}work[3] = { {01,"<<���̸>>",stu[0]},{02,"<<ÿ��һ������С����>>",stu[1]},{03,"<<�籾�����ĵ�>>",stu[2]}};
//	struct book* pb = work;
//	int i = 0;
//	for (pb = work, i = 0; pb < work + 3 && i < 3; pb++, i++)
//	{
//		printf("���:%d\t����:%s\n", pb->num, pb->name);
//		printf("������Ϣ->  num: %d\tname:%s\tsex:%c\tage:%d\n", stu[i].num,stu[i].name,stu[i].sex,stu[i].age);
//	}
//	return 0;
//}

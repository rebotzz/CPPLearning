//day_3

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

////结构体学习
//struct hero
//{
//	char name[25];
//	int age;
//	char sex[10];
//	double hp;
//	double dps;
//	double def;
//};
//
//int main()
//{
//	struct hero milk {"milk", 21,"male",100,400,350 };
//	struct hero adam {"adam",27,"male",130,200,600 };
//	printf("hero_1:\nname:%s\tage:%d\tsex:%s\thp:%lf\tdps:%lf\tdef:%lf\n",
//		milk.name ,milk.age,milk.sex,milk.hp,milk.dps,milk.def);
//	printf("hero_2:\nname:%s\tage:%d\tsex:%s\thp:%lf\tdps:%lf\tdef:%lf\n",
//		adam.name, adam.age, adam.sex, adam.hp, adam.dps, adam.def);
//	return 0;
//}


struct hero
{
	char name[25];
	int age;
	char sex[10];
};

int main()
{
	struct hero adam { "adam", 27, "male"};
	struct hero * padam = &adam;
	printf("hero_2:\nname:%s\tage:%d\tsex:%s\n",
		adam.name, adam.age, adam.sex);
	printf("hero_2:\nname:%s\tage:%d\tsex:%s\n",
		(*padam).name, (*padam).age, (*padam).sex);
	printf("hero_2:\nname:%s\tage:%d\tsex:%s\n",
		padam->name, padam->age, padam->sex);
	return 0;
}

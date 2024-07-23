#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////折扣费计算
//int main()
//{
//	float zhekf = 0;
//	float value = 0;
//	float feip = 0;
//	float year = 0;
//	printf("请依次输入：购买价格 废品价格 使用年限\n");
//	scanf("%f %f %f",&value,&feip,&year);
//	zhekf = (value - feip) / year;
//	printf("折扣费:%0.2f",zhekf);
//	return 0;
//}


//计算还款金额
int main()
{
	float daikun_v = 20000.00;        //贷款金额
	float intreset_year = 0.06;			//年利率
	float month_huanqian = 386.66;		//每个月还款金额
	float shengyu_v[12] = { 0 };		//第i+1个月剩余的需还金额
	float in_month = intreset_year / 12;//月利率
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			shengyu_v[i] = daikun_v * (1 + in_month) - month_huanqian;
			printf("第%d个月剩余的需还金额：%0.2f\n",(i + 1),shengyu_v[i]);
		}
		else
		{
			shengyu_v[i] = shengyu_v[(i - 1)] * (1 + in_month) - month_huanqian;
			printf("第%d个月剩余的需还金额：%0.2f\n", (i + 1), shengyu_v[i]);

		}
	}
	return 0;
}

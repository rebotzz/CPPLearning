#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////getchar()应用
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)     //一个字符一个字符读取输出，以ASSCII码存储，怎样才能终止？
//	{									//getchar()   缓冲区    键盘
//		putchar(ch);
//	}
//
//	return 0;
//}

////getchar()应用2
//int main() 
//{
//	char password[20] = { 0 };
//	printf("请输入密码>:");
//	scanf("%s",password);	//字符数组这里不用 & 符号
//	printf("请确认输入：Y/N\n");
//	int ch = 0;
//	int a = 0;				//清除缓存区的字符，没读取一次，消耗一次, 直到 '\n'  回车
//	while ((a = getchar()) != '\n')
//	{
//		;					//空语句
//	}
//	if ((ch = getchar()) == 'Y')
//	{
//		printf("确认成功");
//	}
//	else
//	{
//		printf("确认失败");
//	}
//	return 0;
//}


//while ;for ;do while 循环的练习

//int main()
//{
//	//for (int i = 0; i < 3; i++)
//	//{
//	//	printf("%d ",i);
//	//}
//
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}


////提取数字
//int main()
//{
//	int ch = 0;
//	while ((ch =getchar()) != EOF)
//	{
//		if (ch < '0' || ch>'9')
//			continue;
//		putchar(ch);
//	}
//	return 0;
//}


////计算 n 的阶乘
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	long long int n_i = n;      //问题（注意）：存储结果有大小限制，超过会  溢出
//	while (n != 1 && n>=1 )
//	{
//		n_i = n_i*(n - 1);
//		n--;
//	}
//	if (n_i >= 0)
//		printf("阶乘为：%lld\n", n_i);	//输出与结果存储大小匹配
//	else
//		//这句话不一定准确，限于目前所学
//		printf("输入值为负数，没有阶乘 or 超过存储大小，结果溢出\n");	
//	return 0;
//}


////计算 n 的阶乘   思路优化
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	long long int n_i = 1;      //问题（注意）：存储结果有大小限制，超过会  溢出
//								//从 n-1 相乘 改为 n+1相乘，减少了判断 n-1 为 0 的情况
//								//但是不能避免 n_i 初始化的问题
//	for(int i=1;i <= n; i++)
//	{
//		n_i = n_i*i;
//	}
//	if (n_i >= 0)
//		printf("阶乘为：%lld\n", n_i);	//输出与结果存储大小匹配
//	else
//		//这句话不一定准确，限于目前所学，或许 多次溢出 后结果为正数
//		printf("输入值为负数，没有阶乘 or 可能超过存储大小，结果溢出\n");	
//	return 0;
//}


////计算 1！+2！+3！……+10！
////思路： 循环嵌套，外层改变n ; 内层求解 n!
//int main()
//{
//									//上一个程序验证 long long int 能存储 15!
//									//所以这里结果存储在 long long int 是可靠的
//	int n = 10;						//注意：存储大小限制，溢出的影响
//	long long int n_i = n;			 
//	long long int sum_n_i = 0;		
//	
//	for (n = 10;n >= 1;n--)         //for 求不同数的阶乘
//	{
//		int i = n;
//		n_i = n;					//不能少这句话，n_i 的初始化   
//		while (i != 0 && i >= 0)	//while 求具体一个数 i 的阶乘
//		{
//			if ((i - 1) == 0)
//				break;
//			n_i = n_i * (i - 1);	//每次 n_i 的初始化数值不同
//			i--;
//			if (i == 1)
//				sum_n_i = sum_n_i + n_i;	//阶乘求和
//		}
//	}
//	printf("1！+2！+3！……+10！= %lld\n",sum_n_i);	//输出结果1！+2！+3！……+10！= 4037912
//	return 0;
//}


////计算 1！+2！+3！……+10！    思路优化
////思路： 循环嵌套，外层改变n ; 内层求解 n!
//int main()
//{
//									//上一个程序验证 long long int 能存储 15!
//									//所以这里结果存储在 long long int 是可靠的
//	int n = 10;						//注意：存储大小限制，溢出的影响
//	long long int n_i = 1;			
//	long long int sum_n_i = 0;		
//	
//	for (n = 10;n >= 1;n--)         //for 求不同数的阶乘
//	{
//		int a = n;					//初始化，很重要，两句都不能少
//		n_i = 1;					//如果少了，结果为 1！+2！+3！……+10！= 3220178247989976832
//		for(int i = 1;i <= a; i++)
//		{
//			n_i = n_i*i;
//			//if (i == a)
//			//	sum_n_i = sum_n_i + n_i;	//等价
//		}
//		sum_n_i += n_i;						//等价
//	}
//	printf("1！+2！+3！……+10！= %lld\n",sum_n_i);	//输出结果1！+2！+3！……+10！= 4037913
//	return 0;
//}


////计算 1！+2！+3！……+10！    思路优化2.0
////思路： 循环嵌套，外层改变n ; 内层求解 n!     (n+1)! = n!*(n+1),利用上一次结果减少循环计算
//int main()
//{
//	int n = 10;						//注意：存储大小限制，溢出的影响
//	long long int n_i = 1;
//	long long int sum_n_i = 0;
//
//	for (n = 1; n <= 10; n++)         //for 求不同数的阶乘
//	{				
//									  //优化了循环计算次数，避免了 sum_n_i 的初始化
//		//3! = 3*2*1 = 3*2!
//		//2! = 2*1
//		n_i = n_i * n;
//		sum_n_i += n_i;						
//	}
//	printf("1！+2！+3！……+10！= %lld\n", sum_n_i);	//输出结果1！+2！+3！……+10！= 4037913
//	return 0;
//}


//// do while 求阶乘
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	int i = 1;
//	long int ret = 1;
//	do
//	{
//		ret *= i;
//		i++;
//	} while (i <= n);
//	printf("阶乘为：%ld\n",ret);
//	return 0;
//}



//// 二分法 查找有序数组中某个元素的下标
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10,14,16,18,20};
//	int k = 16;									//目标元素
//	int lenth = sizeof(arr) / sizeof(arr[0]);	//数组元素个数
//	int left = 0;
//	int right = lenth - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了，目标元素下标为：%d\n", mid);
//			break;
//		}
//	}
//
//	if (left > right)
//	{
//		printf("没有找到，可能目标元素不在查找数组范围\n");
//	}
//
//
//	return 0;
//}


////编写代码，演示多个字符从两端移动，向中间汇聚。
//int main()
//{
//	char arr1[] = "welcome to night city";
//	char arr2[] = "#####################";
//	int lenth = sizeof(arr1) / sizeof(arr1[0]);
//	float mid = (lenth - 1) / 2.0;
//	int left = 0;
//	int right = lenth - 2;
//	printf("%s\n",arr2);
//	printf("按下回车查看以上内容:>");
//	getchar();						//按回车后才继续
//
//	for (int i = left; i < mid; i =i+1 )
//	{
//									//打印左端
//		int a = 0;
//		while (a <= i)
//		{
//			printf("%c", arr1[a]);
//			a++;
//		}
//									//打印中间
//		for (int j = i + 1; j < right - i; j++)
//		{
//			printf("%c", arr2[j]);
//		}
//									//打印右端
//		a = i;						//初始化与上面不同，确保打印字母顺序
//		while (a >= 0)
//		{
//			printf("%c", arr1[right - a]);
//			if (i == right - a)		//解决最后一行中间字符重复打印
//				printf("\b");
//			a--;
//		}
//		//printf("\n");
//		getchar();					//按回车后才继续
//		
//	}
//	return 0;
//}


////////编写代码，演示多个字符从两端移动，向中间汇聚。 改为可以手动输入  代码更改1.0   没有实现，待完成
//////int main()
//////{
//////	char arr1[22] = { 0 };
//////
//////	int ch1 = 0;
//////	int ch2 = 0;
//////
//////	printf("请输入一段字符:>");
//////	for (int n1 = 0; (ch1 = getchar()) != '\n'; n1++)
//////	{
//////		arr1[n1] = getchar();
//////	}
//////	int lenth = sizeof(arr1) / sizeof(arr1[0]);
//////	float mid = (lenth - 1) / 2.0;
//////	int left = 0;
//////	int right = lenth - 2;
//////
//////	printf("按下回车执行:>");
//////	getchar();						//按回车后才继续
//////
//////	for (int i = left; i < mid; i = i + 1)
//////	{
//////		//打印左端
//////		int a = 0;
//////		while (a <= i)
//////		{
//////			printf("%c", arr1[a]);
//////			a++;
//////		}
//////		//打印中间
//////		for (int j = i + 1; j < right - i; j++)
//////		{
//////			printf("#");
//////		}
//////		//打印右端
//////		a = i;						//初始化与上面不同，确保打印字母顺序
//////		while (a >= 0)
//////		{
//////			printf("%c", arr1[right - a]);
//////			if (i == right - a)		//解决最后一行中间字符重复打印
//////				printf("\b");
//////			a--;
//////		}
//////		//printf("\n");
//////		getchar();					//按回车后才继续
//////
//////	}
//////	return 0;
//////}

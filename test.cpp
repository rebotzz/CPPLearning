#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"


int main()
{
	Date d1(2023, 8, 31);
	Date d2;
	d2 = d1;	//d2.operator=(d1);	this÷∏’Î“˛≤ÿ
	(++d2).print();
	//(d2++).print();
	(--d2).print();
	//(d2--).print();

	//cout << (d1 >= d2) << endl;


	(d2+50).print();
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

	return 0;
}
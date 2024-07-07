//#include <climits>
//#include <iostream>
//using namespace std;
//
//
////根据输入的日期，计算是这一年的第几天。
////保证年份为4位数且日期合法。
//
////日期类
//class Date {
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//        : _year(year)
//        , _month(month)
//        , _day(day) {
//    }
//
//    int GetDay()
//    {
//        int month = 1;
//        int day = 1;
//        int sumday = 1; //从1开始,一年的第一天
//        //month
//        while (month != _month)
//        {
//            //cout<<month<<endl;
//            //cout<<GetMonthDay(_year,month)<<endl;
//            sumday += GetMonthDay(_year, month);
//            month++;
//        }
//
//        //day
//        while (day != _day)
//        {
//            sumday++;
//            day++;
//        }
//
//        return sumday;
//    }
//
//    int GetMonthDay(int year, int month) {
//        static int mdays[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//        //判断是否闰年二月
//        if (month == 2
//            && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))   //年是一个整体条件
//        {
//            return 29;
//        }
//        else {
//            return mdays[month];
//        }
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main() {
//    int year, month, day;
//    while (cin >> year >> month >> day) { // 注意 while 处理多个 case
//        Date d(year, month, day);
//        cout << d.GetDay() << endl;
//    }
//
//    return 0;
//}
//// 64 位输出请用 printf("%lld")
//
//
//
//
//
////描述
////有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
////输入描述：
////有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
////输出描述：
////每组数据输出一行，即日期差值
//
//#include <ctime>
//#include <iostream>
//using namespace std;
//
////日期类
//class Date {
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//        : _year(year)
//        , _month(month)
//        , _day(day) {
//    }
//
//    int Gap(Date& d) {
//        int year1 = _year;
//        int year2 = d._year;
//        int gapYear = 0;
//
//        while (year1 != year2) {
//            if (year1 < year2) {
//                if ((year1 % 4 == 0 && year1 % 100 != 0)
//                    || (year1 % 400 == 0)) {
//                    gapYear += 366;
//                }
//                else {
//                    gapYear += 365;
//                }
//                year1++;
//            }
//
//            else {
//                if ((year2 % 4 == 0 && year2 % 100 != 0)
//                    || (year2 % 400 == 0)) {
//                    gapYear -= 366;
//                }
//                else {
//                    gapYear -= 365;
//                }
//                year2++;
//            }
//        }
//
//        return gapYear;
//    }
//
//    int GetDay() {
//        int month = 1;
//        int day = 1;
//        int sumday = 1; //从1开始,一年的第一天
//        //month
//        while (month != _month) {
//            // cout<<month<<endl;
//            // cout<<GetMonthDay(_year,month)<<endl;
//            sumday += GetMonthDay(_year, month);
//            month++;
//        }
//
//        //day
//        while (day != _day) {
//            sumday++;
//            day++;
//        }
//
//        return sumday;
//    }
//
//    int GetMonthDay(int year, int month) {
//        static int mdays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//        //判断是否闰年二月
//        if (month == 2
//            && ((year % 4 == 0 && year % 100 != 0) ||
//                (year % 400 == 0))) { //年是一个整体条件
//            return 29;
//        }
//        else {
//            return mdays[month];
//        }
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main() {
//    int y1, y2;
//    int year1, year2, month1, month2, day1, day2;
//    while (cin >> y1 >> y2) { // 注意 while 处理多个 case
//        year1 = y1 / 10000;
//        year2 = y2 / 10000;
//        day1 = y1 % 100;
//        day2 = y2 % 100;
//        month1 = (y1 - year1 * 10000) / 100;
//        month2 = (y2 - year2 * 10000) / 100;
//
//        // cout<<year1<<"-"<<month1<<"-"<<day1<<endl;
//        // cout<<year2<<"-"<<month2<<"-"<<day2<<endl;
//
//
//        Date d1(year1, month1, day1);
//        Date d2(year2, month2, day2);
//
//        // cout<<"d2:"<<d2.GetDay()<<"  d1:"<<d1.GetDay()<<endl;
//        int gapDay = d2.GetDay() - d1.GetDay();
//        cout << d1.Gap(d2) + gapDay + 1;
//    }
//}
//// 64 位输出请用 printf("%lld")
//
//
//
////2.0
//#include <ctime>
//#include <iostream>
//using namespace std;
//
////日期类
//class Date {
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//        : _year(year)
//        , _month(month)
//        , _day(day) {
//    }
//
//    //2.0   
//    Date& operator+=(int day)
//    {
//        _day += day;
//        int validDay = GetMonthDay(_year, _month);
//        while (_day > validDay)
//        {
//            _day -= validDay;
//            _month++;
//            if (_month > 12)
//            {
//                _month = 1;
//                _year++;
//            }
//            validDay = GetMonthDay(_year, _month);
//        }
//        return *this;
//    }
//
//    bool operator<(Date& d)
//    {
//        if (_year < d._year)
//        {
//            return true;
//        }
//        else if (_year == d._year && _month < d._month)
//        {
//            return true;
//        }
//        else if (_year == d._year && _month == d._month && _day < d._day)
//        {
//            return true;
//        }
//        return false;
//    }
//
//    int operator-(Date& d)
//    {
//        Date max = *this;
//        Date min = d;
//        if (max < min)
//        {
//            max = d;
//            min = *this;
//        }
//
//        int gap = 1;    //题目初始值似乎有问题
//        while (min < max)
//        {
//            min += 1;
//            gap++;
//        }
//
//        return gap;
//    }
//
//    int GetMonthDay(int year, int month) {
//        static int mdays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//        //判断是否闰年二月
//        if (month == 2
//            && ((year % 4 == 0 && year % 100 != 0) ||
//                (year % 400 == 0))) { //年是一个整体条件
//            return 29;
//        }
//        else {
//            return mdays[month];
//        }
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main() {
//    int y1, y2;
//    int year1, year2, month1, month2, day1, day2;
//    while (cin >> y1 >> y2) { // 注意 while 处理多个 case
//        year1 = y1 / 10000;
//        year2 = y2 / 10000;
//        day1 = y1 % 100;
//        day2 = y2 % 100;
//        month1 = (y1 - year1 * 10000) / 100;
//        month2 = (y2 - year2 * 10000) / 100;
//
//        // cout<<year1<<"-"<<month1<<"-"<<day1<<endl;
//        // cout<<year2<<"-"<<month2<<"-"<<day2<<endl;
//        Date d1(year1, month1, day1);
//        Date d2(year2, month2, day2);
//
//        cout << (d2 - d1) << endl;
//    }
//}
//// 64 位输出请用 printf("%lld")
//
//
//
////
////描述
////给出年分m和一年中的第n天，算出第n天是几月几号。
////输入描述：
////输入包括两个整数y(1 <= y <= 3000)，n(1 <= n <= 366)。
////输出描述：
////可能有多组测试数据，对于每组数据， 按 yyyy - mm - dd的格式将输入中对应的日期打印出来。
//
//#include <iostream>
//using namespace std;
//
////日期类
//class Date {
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//        : _year(year)
//        , _month(month)
//        , _day(day) {
//    }
//
//    Date& operator+=(int day) {
//        _day += day;
//        int validDay = GetMonthDay(_year, _month);
//        while (_day > validDay) {
//            _day -= validDay;
//            _month++;
//            if (_month > 12) {
//                _month = 1;
//                _year++;
//            }
//            validDay = GetMonthDay(_year, _month);
//        }
//        return *this;
//    }
//
//    void print()
//    {
//        cout << _year << "-";
//        if (_month < 10)
//        {
//            cout << "0";
//        }
//        cout << _month << "-";
//        if (_day < 10)
//        {
//            cout << "0";
//        }
//        cout << _day << endl;
//
//        // printf("%-4d-%-2d-%-2d\n",_year,_month,_day);
//    }
//
//    int GetMonthDay(int year, int month) {
//        static int mdays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//        //判断是否闰年二月
//        if (month == 2
//            && ((year % 4 == 0 && year % 100 != 0) ||
//                (year % 400 == 0))) { //年是一个整体条件
//            return 29;
//        }
//        else {
//            return mdays[month];
//        }
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main() {
//    int year, days;
//    while (cin >> year >> days) { // 注意 while 处理多个 case
//        Date d(year, 1, 0);
//        d += days;
//        d.print();
//    }
//}
//// 64 位输出请用 printf("%lld")
//
//
//
////描述
////设计一个程序能计算一个日期加上若干天后是什么日期。
////输入描述：
////输入第一行表示样例个数m，接下来m行每行四个整数分别表示年月日和累加的天数。
////输出描述：
////输出m行，每行按yyyy - mm - dd的个数输出。
//
//#include <iostream>
//using namespace std;
//
////日期类
//class Date {
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//        : _year(year)
//        , _month(month)
//        , _day(day) {
//    }
//
//    Date& operator+=(int day) {
//        _day += day;
//        int validDay = GetMonthDay(_year, _month);
//        while (_day > validDay) {
//            _day -= validDay;
//            _month++;
//            if (_month > 12) {
//                _month = 1;
//                _year++;
//            }
//            validDay = GetMonthDay(_year, _month);
//        }
//        return *this;
//    }
//
//    void print() {
//        cout << _year << "-";
//        if (_month < 10) {
//            cout << "0";
//        }
//        cout << _month << "-";
//        if (_day < 10) {
//            cout << "0";
//        }
//        cout << _day << endl;
//
//        // printf("%-4d-%-2d-%-2d\n",_year,_month,_day);
//    }
//
//    int GetMonthDay(int year, int month) {
//        static int mdays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//        //判断是否闰年二月
//        if (month == 2
//            && ((year % 4 == 0 && year % 100 != 0) ||
//                (year % 400 == 0))) { //年是一个整体条件
//            return 29;
//        }
//        else {
//            return mdays[month];
//        }
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main() {
//    int num, year, month, day, days;
//    cin >> num;
//    while (num--) { // 注意 while 处理多个 case
//        cin >> year >> month >> day >> days;
//        Date d(year, month, day);
//        d += days;
//
//        d.print();
//    }
//}
//// 64 位输出请用 printf("%lld")
//
//


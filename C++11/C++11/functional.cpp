#include <iostream>
#include <functional>
using namespace std;

class Func
{
public:
	static void p1()
	{
		cout << "static void p1()" << endl;
	}

	void p2()
	{
		cout << "void p2() -- " << _v << endl;
	}

	void p3(int val)
	{
		cout << "void p3(int val)  -- " << val << endl;
	}
private:
	int _v = 1;
};

//int main()
//{
//	function<void(void)> f1 = []() {cout << "[](){cout}" << endl; };
//	//function<void(void)> f2 = &Func::p1;
//	function<void(void)> f2 = Func::p1;
//	function<void(Func)> f3 = &Func::p2;
//	function<void(Func, int)> f4(&Func::p3);
//	function<void(Func*)> f5 = &Func::p2;	// 指针不如直接对象好，因为：匿名对象，右值不能取地址
//
//	f1();
//	f2();
//	f3(Func());
//	Func tmp;
//	f4(tmp, 3);
//	cout << "---------" << endl;
//	//f5(&Func());	// 右值不能取地址
//	f5(&tmp);
//
//
//		return 0;
//}


//////////////////////////////////////////////
// 逆波兰表达式求值
// 输入：tokens = ["2","1","+","3","*"]
//输出：9
//解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
//
#if 0
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        size_t index = 0;
        int num;

        // 使用function制作函数映射表: 便于后期修改
        map<string, function<int(int, int)>> callback = {
            {"+", [](int x, int y) {return x + y; }},
            {"-", [](int x, int y) {return x - y; }},
            {"*", [](int x, int y) {return x * y; }},
            {"/", [](int x, int y) {return x / y; }}
        };

        while (index < tokens.size())
        {
            //将数字入栈
            if (tokens[index] != "+"
                && tokens[index] != "-"
                && tokens[index] != "*"
                && tokens[index] != "/")
            {
                num = stoi(tokens[index]);
                st.push(num);
                index++;
            }

            else
            {
                int rightNum = st.top();
                st.pop();
                int leftNum = st.top();
                st.pop();

                //遇到运算符出栈两个数字进行运算,结果再入栈
                st.push(callback[tokens[index]](leftNum, rightNum));
                index++;
            }


        }

        //直到tokens结束,返回栈顶结果
        return st.top();
    }
};

#endif





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
//	function<void(Func*)> f5 = &Func::p2;	// ָ�벻��ֱ�Ӷ���ã���Ϊ������������ֵ����ȡ��ַ
//
//	f1();
//	f2();
//	f3(Func());
//	Func tmp;
//	f4(tmp, 3);
//	cout << "---------" << endl;
//	//f5(&Func());	// ��ֵ����ȡ��ַ
//	f5(&tmp);
//
//
//		return 0;
//}


//////////////////////////////////////////////
// �沨�����ʽ��ֵ
// ���룺tokens = ["2","1","+","3","*"]
//�����9
//���ͣ�����ʽת��Ϊ��������׺�������ʽΪ��((2 + 1) * 3) = 9
//
#if 0
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        size_t index = 0;
        int num;

        // ʹ��function��������ӳ���: ���ں����޸�
        map<string, function<int(int, int)>> callback = {
            {"+", [](int x, int y) {return x + y; }},
            {"-", [](int x, int y) {return x - y; }},
            {"*", [](int x, int y) {return x * y; }},
            {"/", [](int x, int y) {return x / y; }}
        };

        while (index < tokens.size())
        {
            //��������ջ
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

                //�����������ջ�������ֽ�������,�������ջ
                st.push(callback[tokens[index]](leftNum, rightNum));
                index++;
            }


        }

        //ֱ��tokens����,����ջ�����
        return st.top();
    }
};

#endif





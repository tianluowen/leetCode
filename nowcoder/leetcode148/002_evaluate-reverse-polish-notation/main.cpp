// date: 2020-03-29
// desc: 002_计算逆波兰式（后缀表达式）的值

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        
        int size = tokens.size();
        // 定义操作数 和 结果变量 避免 - / 法操作数顺序问题
        int opt1;
        int opt2;
        int vaule;
        char ch;
        // 取出每个一个字符串
        for (int i = 0; i < size; i++)
        {
            string str = tokens[i];
            ch = str[0];
            // 判断该字符串是不是操作符，是的话取值操作，不是的话，将字符串转换为 int 数值，放入 队列
            if (str.size() == 1 && (ch == '+' || ch == '-' || ch == '*' || ch == '/'))
            {
                if (ch == '+')
                {
                    opt1 = s.top();
                    s.pop();
                    opt2 = s.top();
                    s.pop();
                    s.push(opt1 + opt2);
                }
                if (ch == '-')
                {
                    opt1 = s.top();
                    s.pop();
                    opt2 = s.top();
                    s.pop();
                    s.push(opt2 - opt1);
                }
                if (ch == '*')
                {
                    opt1 = s.top();
                    s.pop();
                    opt2 = s.top();
                    s.pop();
                    s.push(opt1 * opt2);
                }
                if (ch == '/')
                {
                    opt1 = s.top();
                    s.pop();
                    opt2 = s.top();
                    s.pop();
                    s.push(opt2 / opt1);
                }
            }
            else // 该字符串是数值的情况
            {
                vaule = stoi(str);
                s.push(vaule);
            }
        }
        // 返回队列里最后一个数据 就是结果
        return s.top();
    }
};        


int main(void)
{
    Solution s;


    vector<string> vs = {"2", "1", "+", "3", "*"};
    int result = s.evalRPN(vs);

    cout << "逆波兰表达式输入为: [\"2\", \"1\", \"+\", \"3\", \"*\"]" << endl;
    cout << "计算结果 = " << result << endl;


    return 0;
}

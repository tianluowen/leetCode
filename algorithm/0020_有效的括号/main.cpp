// date: 2020-05-15
// desc: 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//       有效字符串需满足：
//       左括号必须用相同类型的右括号闭合。
//       左括号必须以正确的顺序闭合。
//       注意空字符串可被认为是有效字符串。

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        // 依次遍历
        for (auto ch : s)
        {
            switch (ch)
            {
                // 入栈
                case '(':
                case '{':
                case '[':
                    st.push(ch);
                    break;
                // 取值判断是否相等
                case ')':
                    if (st.empty() || st.top() != '(')
                        return false;
                    st.pop();
                    break;
                case '}':
                    if (st.empty() || st.top() != '{')
                        return false;
                    st.pop();
                    break;
                case ']':
                    if (st.empty() || st.top() != '[')
                        return false;
                    st.pop();
                    break;
                default:
                    break;
            }
        }

        // 此时栈不为空 返回 false
        if (!st.empty())
            return false;
        else
            return true;
    }
};

int main(void)
{
    Solution s;
    string str("([{}])");
    
    bool result = s.isValid(str);

    cout << str << endl;
    cout << "result = " << boolalpha << result << endl;

    return 0;
}

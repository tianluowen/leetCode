// date: 2020-05-21
// desc: 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxleng = 0;
        int s_size = s.size();

        int left = 0;
        int right = 0;
        // 从左到右
        for (auto ch : s)
        {
            if (ch == '(')
                left++;
            else 
                right++;
            
            if (right > left)
            {
                left = 0;
                right = 0;
            }
            else if (right == left)
                maxleng = max(maxleng, left + right);
        }

        // 从右到左
        left = 0;
        right = 0;
        for (int index = s_size - 1; index >= 0; index--)
        {
            if (s[index] == '(')
                left++;
            else 
                right++;
            
            if (left > right)
            {
                left = 0;
                right = 0;
            }
            else if (right == left)
                maxleng = max(maxleng, left + right);
        }

        return maxleng;
    }
};

int main(void)
{
    Solution s;
    string str("(()");

    int result = s.longestValidParentheses(str);

    cout << "\"" << str << "\"" << endl;
    cout << "result = " << result << endl;

    return 0;
}

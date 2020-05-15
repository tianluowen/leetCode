// date: 2020-05-15
// desc: 给出n对括号，请编写一个函数来生成所有的由n对括号组成的合法组合。
//       例如，给出n=3，解集为：
//       "((()))", "(()())", "(())()", "()(())", "()()()"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> result;
    string strtemp;
    int s_size;
    int left = 0;       // 记录左括号数量
    int right = 0;      // 记录右括号数量

    vector<string> generateParenthesis(int n) {
        strtemp = string(2 * n, '\0');
        s_size = strtemp.size();

        // 递归生存 所有可能
        GetValidBrackets(0);

        return result;
    }

    void GetValidBrackets(int n)
    {
        // 当左右括号数量相等
        if (n == s_size)
        {
            if (left == right)
                result.push_back(strtemp);
            
            return;
        }

        // 先放入左括号，如何合理 继续递归
        left++;
        if (left > right && left <= s_size / 2)
        {
            strtemp[n] = '(';
            GetValidBrackets(n + 1);
        }

        // 去调左括号，放入右括号，如果合理 继续递归
        left--;
        right++;
        if (left >= right)
        {
            strtemp[n] = ')';
            GetValidBrackets(n + 1);
        }
        // 去掉右括号，回溯，返回上一个位置继续判断
        right--;

        return;
    }
};

int main(void)
{
    Solution s;
    
    vector<string> result = s.generateParenthesis(4);

    cout << "4" << endl;
    cout << endl << "[" << endl;
    for (int index = 0; index < result.size(); index++)
    {
        cout << "  \"" << result[index] << "\"";
        if (index != result.size() - 1)
            cout << ",";
        cout << endl;
    }
    cout << "]" << endl;

    return 0;
}

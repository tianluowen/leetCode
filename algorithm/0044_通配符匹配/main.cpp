// date: 2020-06-02
// desc: 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
//       '?' 可以匹配任何单个字符。
//       '*' 可以匹配任意字符串（包括空字符串）。
//       两个字符串完全匹配才算匹配成功。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_length = s.length();
        int p_length = p.length();
        vector<vector<bool>> dp(s_length + 1, vector<bool>(p_length + 1, false));

        // dp init
        dp[0][0] = true;
        for (int index = 1; index <= p_length; index++)
        {
            dp[0][index] = dp[0][index - 1] && p[index - 1] == '*';
        }

        // 动态规划
        for (int s_index = 1; s_index <= s_length; s_index++)
        {
            for (int p_index = 1; p_index <= p_length; p_index++)
            {
                if (s[s_index - 1] == p[p_index - 1] || p[p_index - 1] == '?')
                    dp[s_index][p_index] = dp[s_index - 1][p_index - 1];
                else if (p[p_index - 1] == '*')
                {
                    dp[s_index][p_index] = dp[s_index][p_index - 1] || dp[s_index - 1][p_index];
                }

            }
        }   

        return dp[s_length][p_length];
    }
};

int main(void)
{
    Solution s;
    string str("aa");
    string pat("a");
    
    bool result = s.isMatch(str, pat);

    cout << "str = " << str << ", pat = " << pat << endl;
    cout << "result = " << boolalpha << result << endl;

    return 0;
}

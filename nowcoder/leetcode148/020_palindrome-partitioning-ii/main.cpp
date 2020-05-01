// date: 2020-05-01
// desc: 给出一个字符串s，分割s使得分割出的每一个子串都是回文串
//       计算将字符串s分割成回文分割结果的最小切割数
//       例如:给定字符串s="aab",
//       返回1，因为回文分割结果["aa","b"]是切割一次生成的。

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution { public: int minCut(string s) {
        int  len = s.size();
        vector<vector<bool>> flag(len, vector<bool>(len, false));
        vector<int> dp(len,  len);
        int temp = len;
        
        for (int i = 0; i < len; ++i)
        {
            temp = i;
            for (int j = 0; j <= i; ++j)
            {
                if (s[j] == s[i] && (i - j <= 2 || flag[i - 1][j + 1]))
                {
                    flag[i][j] = true;
                    temp = min(temp, j == 0 ? 0 : dp[j - 1] + 1);
                }
            }
            dp[i] = temp;
        }
        
        return dp[len - 1];
    }
};
        
int main(void)
{
    Solution s;

    int result = s.minCut("aab");

    cout << "str = \"aab\"" << endl;

    cout << "result = " << result << endl;

    return 0;
}

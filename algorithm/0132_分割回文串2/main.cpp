// date: 2020-05-01
// desc: 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
//       返回符合要求的最少分割次数。

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

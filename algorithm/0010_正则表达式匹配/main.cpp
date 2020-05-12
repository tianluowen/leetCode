// date: 2020-05-04
// desc: 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*class Solution {
public:
    bool isMatch(string s, string p) {

        // return regex_match(s, regex(p));

        if (s.length() == 0 && p.length() == 0)
            return true;
        
        bool match = (s.length() > 0 && (s[0] == p[0] || p[0] == '.'));
        if (p.length() > 1 && p[1] == '*')
        {
            return isMatch(s, p.substr(2)) || (match && isMatch(s.substr(1), p));
        } 
        else 
        {
            return match && isMatch(s.substr(1), p.substr(1));
        }



        
    }
};
*/

//方法二：动态规划
/*
* 状态 dp[i][j] : 表示 s 的前 i 个字符和 p 的前 j 个字符是否匹配 (true 的话表示匹配)
* 状态转移方程：
*      1. 当 s[i] == p[j]，或者 p[j] == '.' ,那么 dp[i][j] = dp[i - 1][j - 1];
*      2. 当 p[j] == '*' 。分两种情况：
*       情况1：若 s[i] != p[j - 1] or p[j -1] != '.'。那么 dp[i][j] = dp[i][j - 2]，表示当前'*'无效
*       情况2：dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j]   
* 其中：
*      dp[i][j - 1] 表示 '*' 匹配一个字符，例如 a, a*
*      dp[i][j - 2] 表示 '*' 不匹配任何字符，例如 a, aa*
*      dp[i - 1][j] 表示 '*' 匹配多个字符，例如 abbb, ab*
* 初始化：
*      1. dp[0][0] 表示什么都没有，其值为 true
*      2. 第一行 dp[0][j]，换句话说，s 为空，与 p 匹配，所以只要 p 开始的第二个元素为 '*' 才有可能为 true
*      3. 第一列 dp[i][0]，当然全部为 false
*/
//时间复杂度：O(n*m)。
//空间复杂度：O(n*m)。
class Solution {
public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int j = 2; j <= n; ++j)
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*'; //初始化
        
        for(int i = 1; i <= m; ++i) //注意：实际的索引为i - 1, j - 1。因为第 1 个的索引实际为0
        {
            for(int j = 1; j <= n; ++j)
            {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.') //当前字符匹配
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*') //当前p字符为*
                {
                    if(s[i - 1] != p[j - 2] && p[j - 2] != '.') //*前的字符与s的字符不匹配
                        dp[i][j] = dp[i][j - 2]; //忽略*号
                    else
                        dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j]; //匹配1个，匹配0个和匹配多个
                }
            }
        }
        return dp[m][n];
    }
};

int main(void)
{
    Solution s;

    cout << "s = aab, p = a*b" << endl;
    cout << boolalpha << s.isMatch("aab", "a*b") << endl;

    return 0;
}

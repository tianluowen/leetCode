// date: 2020-04-24
// desc: 给定一个字符串s和一组单词dict，判断s是否可以用空格分割成一个单词序列
//       使得单词序列中所有的单词都是dict中的单词（序列可以包含一个或多个单词）。

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;
        
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int slength = s.size();
        vector<bool> vb(dict.size() + 1, false);
        
        // 输入字符串长度为 0 一定是可以拆分的
        vb[0] = true;
        for (int i = 1; i <= slength; i++)
        {
            // 从 0 开始，每次增加一个长度，
            for (int j = i - 1; j >= 0; j--)
            {
                if (vb[j] == true && dict.find(s.substr(j, i - j)) != dict.end())
                {
                    vb[i] = true;
                    break;
                }
            }
        }
        return vb[s.size()];
    }
};

int main(void)
{
    Solution s;
    std::unordered_set<std::string> dict = { "leet","code" };
    bool result = s.wordBreak("leetcode", dict);

    cout << "s = leetcode\n";
    cout << "dict = {leet, code}\n";
    cout << "restult = " << result << endl;

    return 0;
}

// date: 2020-04-24
// desc: 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;
        
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    int slength = s.size();
    vector<bool> vb(s.size() + 1, false);
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
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
    vector<std::string> dict = { "leet","code" };
    bool result = s.wordBreak("leetcode", dict);

    cout << "s = leetcode\n";
    cout << "dict = {leet, code}\n";
    cout << "restult = " << result << endl;

    return 0;
}

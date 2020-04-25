// date: 2020-04-25
// desc: 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;
        
class Solution {
private:
    string str;                     // 传入需要判断的字符
    unordered_set<string> dict;     // 保存传入的字典
    vector<string> words;           // 保存拆分的单词
    vector<string> result;          // 记录所有的返回结果
    int size; 

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        str = s;
        size = s.size();

        if (isbreak(s, wordDict))
        {
            // 从开始调用递归函数判断
            dfs(0);
        }

        return result;
    }

    void dfs(int begin)
    {
        // 找到一种方式 将结点转换为字符串添加到容器中 并 返回
        if (begin >= size)
        {
            // 临时变量，在单词之间加上空格
            string temp;
            for (int i = 0; i < words.size(); i++)
            {
                temp += words[i];
                temp += " ";
            }
            // 删除最后一个空格，并将字符串放到返回容器中
            temp.pop_back();
            result.insert(result.begin(), temp);

            return;
        }

        // 判断 begin 后面的字符 第一次的时候 直接将结点 记录，第二次要先删除，在记录
        int flag = false;
        for (int i = begin; i < size; i++)
        {
            if (dict.find(str.substr(begin, i - begin + 1)) != dict.end())
            {
                if (flag)
                {
                    words.pop_back();
                }
                flag = true;
                words.push_back(str.substr(begin, i - begin + 1));
                dfs(i + 1);
            }
        }

        // 执行完了后，如果有添加，则删除
        if (flag)
        {
            words.pop_back();
        }

        return;
    }

    bool isbreak(string s, vector<string>& wordDict) {
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
    vector<std::string> dict = { "leet","code", "lee", "tcode" };
    vector<string> result;
    result = s.wordBreak("leetcode", dict);

    cout << "s = leetcode\n";
    cout << "dict = {leet, code, lee, tcode}\n";
    cout << endl;
    for (auto s : result)
        cout << s << endl;

    return 0;
}

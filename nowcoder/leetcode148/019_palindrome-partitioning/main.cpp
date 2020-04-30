// date: 2020-04-30
// desc: 题目描述
//       给定一个字符串s，分割s使得s的每一个子串都是回文串
//       返回所有的回文分割结果。（注意：返回结果的顺序需要和输入字符串中的字母顺序一致。）

#include <iostream>
#include <vector>
#include <string>

using namespace std;
        
class Solution {
private:
    string str;                     // 保存判断字符串
    int size;                       // 保存判断字符串的长度
    vector<string> words;           // 保存所有返回结果
    vector<vector<string>> result;  // 保存所有返回结果
    
public:
    vector<vector<string>> partition(string s) {
        str = s;
        size = s.size();

        // 递归求解
        dfs(0);
        
        return result;
    }
    
    void dfs(int i)
    {
        if (i == size)
        {
            result.push_back(words);
            return;
        }
        
        int flag = false;
        // 获取 i 字节后面的第一个 回文字符串
        for (int begin = i; begin < size; ++begin)
        {
            if (is_huiwen(str.substr(i, begin - i + 1)))
            {   
                if (flag)
                {
                    words.pop_back();
                }
                flag = true;
                words.push_back(str.substr(i, begin - i + 1));
                dfs(begin + 1);
            }
        }
        
         // 如果 flag = true 说明放入一个字符串，取出字符串
        if (flag)
        {
            words.pop_back();
        }
        
        return;
    }
    
    bool is_huiwen(string s)
    {
        int begin = 0;
        int end = s.size() - 1;
        for (;begin < end; ++begin, --end)
        {
            if (s[begin] != s[end])
            {
                return false;
            }
        }

        return true;
    }
};
        
int main(void)
{
    Solution s;
    string str {"aab"};
    vector<vector<string>> result;

    result = s.partition(str);

    cout << "test str = \"aab\"" << endl;

    for (int i = 0; i < result.size(); ++i)
    {
        cout << "[ ";
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout << "\"" << result[i][j] << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}

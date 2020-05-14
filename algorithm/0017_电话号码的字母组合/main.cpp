// date: 2020-05-14
// desc: 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//       给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> result;
    const char * strs[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int size;
    string s;
    string temp;

    vector<string> letterCombinations(string digits) {
        size = digits.size();
        s = digits;

        if (digits.size() != 0)
        {
            dfs(0);
        }

        return result;
    }

    // 递归调用
    void dfs(int index)
    {
        if (index == size)
        {
            result.push_back(temp);
            return;
        }

        int flag = false;
        const char *p;
        for(p = strs[s[index] - '0' - 2]; *p != '\0'; ++p)
        {
            if (!flag)
            {
                flag = true;
                temp += *p;
            }
            else
            {
                // 第二次时取出上个字符
                temp.pop_back();
                temp += *p;
            }
            dfs(index + 1);
        }

        // 取出这层写入的字符
        temp.pop_back();

        return;
    }
};

int main(void)
{
    Solution s;
    string digits("74");
    vector<string> result;
    
    result = s.letterCombinations(digits);

    cout << "74" << endl << endl;

    for (auto str : result)
        cout << str << endl;

    return 0;
}

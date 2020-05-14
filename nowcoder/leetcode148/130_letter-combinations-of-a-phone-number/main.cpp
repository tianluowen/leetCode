// date: 2020-05-14
// desc: 给出一个仅包含数字的字符串，给出所有可能的字母组合。
//       数字到字母的映射方式如下:(就像电话上数字和字母的映射一样)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> result;
    const char *strs[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
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
        else
        {
            result.push_back("");
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

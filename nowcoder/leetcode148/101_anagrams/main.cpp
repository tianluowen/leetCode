// date: 2020-06-14
// desc: 给出一个字符串数组，返回所有互为“换位词（anagrams）”的字符串的组合。（换位词就是包含相同字母，但字母顺序可能不同的字符串）
//       备注：所有的输入都是小写字母
//       例如：
//       输入["tea","and","ate","eat","den"]
//       返回
//       [["ate", "eat","tea"],  ["nat","tan"],  ["bat"]]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<vector<string>> result;
        vector<string> comparestr;
        vector<string> result2;

        // 依次排序判断每一个字符串
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            
            sort(temp.begin(), temp.end());
            int index = 0;
            // 寻找该字符串顺序是否在前面出现过
            for (; index < comparestr.size(); index++)
            {
                if (comparestr[index] == temp)
                    break;
            }

            // 新的字符串顺序
            if (index == comparestr.size())
            {
                comparestr.push_back(temp);
                result.push_back({strs[i]});
            }
            else
            {
                result[index].push_back(strs[i]);
            }
        }
        
        for (int i = 0; i < result.size(); i++)
        {
            comparestr = result[i];
            if (comparestr.size() > 1)
            {
                for (int j = 0; j < comparestr.size(); j++)
                {
                    result2.push_back(comparestr[j]);
                }
            }
        }
        
        sort(result2.begin(), result2.end());
        
        return result2;
    }
};

int main(void)
{
    Solution s;
    vector<string> strs {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<string> result = s.anagrams(strs);

    cout << "[";
    for (int i = 0; i < strs.size(); i++)
    {
        if (i != strs.size() - 1)
        {
            cout << "\"" << strs[i] << "\", ";
        }
        else
        {
            cout << "\"" << strs[i] << "\"]";
        }
    }
    cout << endl;


    cout << endl;
    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        if (i != result.size() - 1)
        {
            cout << "\"" << result[i] << "\", ";
        }
        else
        {
            cout << "\"" << result[i] << "\"]";
        }
    }
    cout << endl;

    return 0;
}

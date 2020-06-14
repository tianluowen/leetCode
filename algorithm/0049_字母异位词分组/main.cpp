// date: 2020-06-14
// desc: 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
//       示例:
//       输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
//       输出:
//       [
//         ["ate","eat","tea"],
//         ["nat","tan"],
//         ["bat"]
//       ]
//       说明：
//       所有输入均为小写字母。
//       不考虑答案输出的顺序。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<string> comparestr;

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

        return result;
    }
};

int main(void)
{
    Solution s;
    vector<string> strs {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> result = s.groupAnagrams(strs);

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
    cout << "[\n";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "  [";
        vector<string> data = result[i];
        for (int j = 0; j < data.size(); j++)
        {
            if (j != data.size() - 1)
            {
                cout << "\"" << data[j] << "\", ";
            }
            else
            {
                cout << "\"" << data[j] << "\"";
            }
        }

        if (i != result.size() - 1)
        {
            cout << "]," << endl;
        }
        else
        {
            cout << "]" << endl;
        }
    }
    cout << "]" << endl;

    return 0;
}

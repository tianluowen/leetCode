// date: 2020-03-19
// desc: 编写一个函数来查找字符串数组中的最长公共前缀。
//       如果不存在公共前缀，返回空字符串 ""。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        
        if (strs.size() == 0)
            return result;
        
        for(int i = 0; i < strs[0].size(); i++)
        {
            char tempch = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (tempch != strs[j][i])
                    return result;
            }
            result += tempch;
        }

        return result;
    }
};

int main(void)
{
    Solution s;
    vector<string> strs {"flower", "flow", "flight"};

    cout << "flower, flow, flight" << endl;
    cout << s.longestCommonPrefix(strs) << endl;

    return 0;
}

// date: 2020-05-02
// desc: 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        string result;
        vector<string> v (nRows);

        if (nRows == 1)
            return s;

        int flag = -1;
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            v[j] += s[i]; 

            if (j == nRows - 1 || j == 0)
            {
                 flag *= -1;
            }
          
            j += flag;  
        }

        for (int i = 0; i < nRows; i++)
            result += v[i];
            
        return result;
    }
};


int main(void)
{
    Solution s;

    cout << "输入: \"LEETCODEISHIRING\", nRows = 3" << endl;
    cout << "result: \"" << s.convert("LEETCODEISHIRING", 3) << "\"" << endl;

    return 0;
}

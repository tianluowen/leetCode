// date: 2020-05-12
// desc: 请将给出的罗马数字转化为整数
//       保证输入的数字范围在1 到 3999之间。

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ral = 0;
        unordered_map<char, int>bp = { { 'I',1 },{ 'V', 5 },{ 'X', 10 },{ 'L' , 50 },{ 'C' , 100 },{ 'D' , 500 },{ 'M' , 1000 } };
        
        int s_size = s.size();
        for (int i = 0; i < s_size; i++)
        {
            int res = bp[s[i]];
            if (i == s_size - 1 || bp[s[i + 1]] <= bp[s[i]])
                ral += res;
            else 
                ral -= res;
        }

        return ral;
    }
};

int main(void)
{
    Solution s;

    int result = s.romanToInt("III");

    cout << "III" << endl;
    cout <<  result << endl; 

    return 0;
}

// date: 2020-05-12
// desc: 给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result;
        int data[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const char *rom[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        for (int index = 0; index < 13;)
        {
            if (num >= data[index])
            {
                result += rom[index];
                num -= data[index];    
            }
            else
            {
                index++;
            }
        }

        return result;
    }
};

int main(void)
{
    Solution s;

    string result = s.intToRoman(1234);

    cout << "1234" << endl;
    cout <<  result << endl; 

    return 0;
}

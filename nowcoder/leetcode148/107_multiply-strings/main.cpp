// date: 2020-06-02
// desc: 给出两个用字符串表示的数字，将两个数字的乘积作为字符串返回。
//       备注：数字可以无限大，且是非负数。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string result;
        string modstr("");
        string temp;

        // 依次处理每一位
        int indexleng = num1.length();
        for (int index = 0; index < indexleng; index++)
        {
            temp = multStrAndNum(num2, num1[index] - '0');
            temp = modstr + temp;
            result = sumTwoStr(result, temp);

            modstr += '0';
        }

        // 处理前面多余的 0
        for (int index = result.length() - 1; index > 0; index--)
        {
            if (result[index] != '0')
                break;
            else
                result.pop_back();
        }

        reverse(result.begin(), result.end());
        return result;
    }

    // 字符串 乘以 num = (0, 9)
    string multStrAndNum(string num1, int num2)
    {
        // 0 1 特殊情况
        if (num2 == 0)
            return "0";
        if (num2 == 1)
            return num1;
        
        string result;
        int indexleng = num1.length();
        int mult = 0;
        int mod = 0;
        // 处理每一位
        for (int index = 0; index < indexleng; index++)
        {
            mult = (num1[index] - '0') * num2 + mod;
            mod = mult / 10;
            mult = mult % 10;

            result += (mult + '0');   
        }

        // 处理进制
        if (mod != 0)
            result += (mod + '0');

        return result;
    }

    // 实现两个字符串相加
    string sumTwoStr(string num1, string num2)
    {
        // 其中一个为空
        if (num1 == "")
            return num2;
        if (num2 == "")
            return num1;
        
        string result;
        int numleng1 = num1.length();
        int numleng2 = num2.length();
        int indexleng = min(numleng1, numleng2);
        int sum = 0;
        int mod = 0;

        // 处理相同的位数
        for (int index = 0; index < indexleng; index++)
        {
            sum = num1[index] - '0' + num2[index] - '0' + mod;
            mod = sum / 10;
            sum = sum % 10;

            result += (sum + '0'); 
        }

        // 处理较长的部分
        if (numleng1 < numleng2)
        {
            result += num2.substr(indexleng, numleng2 - indexleng);
        }
        if (numleng1 > numleng2)
        {
            result += num1.substr(indexleng, numleng1 - indexleng);
        }

        // 处理进制
        for (int index = indexleng; index < result.length(); index++)
        {
            sum = result[index] + mod - '0';
            mod = sum / 10;
            sum = sum % 10;

            result[index] = sum + '0'; 
        }
        
        if (mod != 0)
            result += (mod + '0');

        return result;
    }
};

int main(void)
{
    Solution s;
    string num1("123");
    string num2("456");
    
    string result = s.multiply(num1, num2);

    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
    cout << "result = " << result << endl;

    return 0;
}

// date: 2020-05-03
// desc: 实现函数 atoi 。函数的功能为将字符串转化为整数

#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        int index = 0;
        //int length = str.length();
        int flag = 1;
        int result = 0;

        // 跳过空白
        while (str[index] == ' ')
            ++index;

        // 判断正负
        if (str[index] < '0' || str[index] > '9')
        {
            if (str[index] == '-')
            {
                flag = -1;
                ++index;
            }
            else if (str[index] == '+')
            {
                flag = 1;
                ++index;
            }
            else
            {
                return 0;
            }
        }

        // 转换
        while (str[index] != '\0')
        {
            // 添加正负说明
            if (result != 0 && flag != 0)
            {
                result *= flag;
                flag = 0;
            }

            if (str[index] >= '0' && str[index] <= '9')
            {
                // 判断是否溢出
                if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[index] - '0' > 7))
                    return INT_MAX;
            
                if (result < INT_MIN / 10 || (result == INT_MIN / 10 && -(str[index] - '0') < -8))
                {
                    // cout << "test test " << endl;
                    return INT_MIN;
                }
                
                result *= 10;
                if (result >= 0)
                    result += str[index] - '0';
                else 
                    result -= str[index] - '0';
            }
            else
            {
                break;
            }

            ++index;
        }

        // flag 未使用
        if (flag != 0)
            result *= flag;

        return result;
    }
};

int main(void)
{
    Solution s;

    cout << "input = 42" << endl;
    cout << "result = " << s.atoi("42") << endl;

    return 0;
}

// date: 2020-05-17
// desc: 在不使用乘法运算符，除法运算符和取余运算符的情况下对两个数进行相除操作

#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 异常处理
        if (dividend == INT_MIN)
        {
            if (divisor == -1)
                return INT_MAX;
            if (divisor == 1)
                return INT_MIN;
        }

        int sign = 1;
        int result;

        // 先将两个数都转换为负数
        // sign 标记，同号为 +1 异号为 -1
        if (dividend > 0)
        {
            dividend = -dividend;
            sign = -sign;
        }
        if (divisor > 0)
        {
            divisor = -divisor;
            sign = -sign;
        }

        // 递归调用计算结果
        result = div(dividend, divisor);

        // 根据符号返回正确的结果
        return sign > 0 ? result : -result;
        
    }

    int div(int dividend, int divisor)
    {
        // 因为是负数处理
        if (divisor < dividend)
            return 0;

        int result = 1;
        int tempdivisor = divisor;
        while (true)
        {
            if (dividend - tempdivisor <= tempdivisor)
            {
                // 所有结果翻倍
                result = result + result;
                tempdivisor = tempdivisor + tempdivisor;
            }
            else  // 递归调用
            {
                return result + div(dividend - tempdivisor, divisor);
            }
        }
    }
};

int main(void)
{
    Solution s;
    int dividend = 123456789;
    int divisor = 123;

    int result = s.divide(dividend, divisor);

    cout << "dividend = " << dividend << ", divisor = " << divisor << endl;
    cout << "result = " << result << endl;

    return 0;
}

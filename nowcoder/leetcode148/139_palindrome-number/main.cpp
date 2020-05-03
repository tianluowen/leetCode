// date: 2020-05-03
// desc: 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数

#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
bool isPalindrome(int x) {
        // 负数返回 false
        if (x < 0)
            return false;

        // 转换这个数
        if (x == reverse(x))
            return true;
        else
            return false;
    }

    int reverse(int x) {
        int result = 0;
        int pos = 0;

        while (x != 0)
        {
            pos = x % 10;
            
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pos > 7)) 
                return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pos < -8)) 
                return 0;
            
            result *= 10;
            result += pos;
            x = x / 10;
        }
        
        return result;
    }
};


int main(void)
{
    Solution s;
    int num = 12321;

    cout << "num = " << num << endl;
    cout << boolalpha << s.isPalindrome(num) << endl;

    return 0;
}

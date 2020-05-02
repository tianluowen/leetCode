// date: 2020-05-02
// desc: 将给出的整数x翻转

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
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
    int num = -123456789;

    cout << "num = " << num << endl;
    cout << "res = " << s.reverse(num) << endl;

    return 0;
}

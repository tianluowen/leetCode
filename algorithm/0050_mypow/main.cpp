// date: 2020-06-14
// desc: 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
//       输入: 2.00000, 10
//       输出: 1024.00000

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {     
        long long N = n;
       
        return n < 0 ? 1 / quikMuilt(x, -N) : quikMuilt(x, n);
    }   

    double quikMuilt(double x, long long n )
    {
        if (n == 0)
            return 1.0;

        double result = quikMuilt(x, n / 2);
        
        return n % 2 == 0 ? result * result : result * result * x;
    }
};

int main(void)
{
    Solution s;
    double x = 2.0;
    int n = 10;

    double result = s.myPow(x, 10);
    
    cout << "x = " << x << ", n = " << n << endl;
    cout << "result = " << result << endl;

    return 0;
}

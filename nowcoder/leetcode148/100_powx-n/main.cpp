// date: 2020-06-14
// desc: 请实现函数 pow(x, n).
//       Implement pow(x, n).

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double pow(double x, int n) {     
        long long N = n;
       
        return n < 0 ? 1 / quikMuilt(x, -N) : quikMuilt(x, n);
    }   

    double quikMuilt(double x, double num)
    {
        long long n = (long long)num;
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
    double n = 10.0;

    double result = s.pow(x, 10);
    
    cout << "x = " << x << ", n = " << n << endl;
    cout << "result = " << result << endl;

    return 0;
}

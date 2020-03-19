// date: 2020-03-19
// desc: 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内

#include <string>
#include <iostream>

using namespace std;

enum romenum
{
    I,
    V,
    X,
    L,
    C,
    D,
    M
};


class Solution {
public:
    int romanToInt(string s) {
        
        romenum now = (romenum)0;
        romenum last = (romenum)0;

        for (int i = 0; i < s.size(); i++)
        {
            last = now;
            switch (s[i])
            {
                case 'I':
                    now = I;
                    break;
                case 'V':
                    now = V;
                    break;
                case 'X':
                    now = X;
                    break;
                case 'L':
                    now = L;
                    break;
                case 'C':
                    now = C;
                    break;
                case 'D':
                    now = D;
                    break;
                case 'M':
                    now = M;
                    break;
                default:
                    return -1;
                    break;
            }

            if (i > 0)
            {
                if (last < now)
                {
                    num += -vaule[last];
                }
                else
                {
                    num += vaule[last];
                }
            }
            // cout << "i = " << i << ", now = " << now << ", last = " << last << ", vaule[now] = "
            //     << vaule[now] << ", vaule[last] = " << vaule[last] << ", num = " << num << endl;
        }
        num += vaule[now];

        return num;
    }

private:
    int num  = 0;
    int vaule[M + 1] = { 1, 5, 10, 50, 100 ,500, 1000 };
};

int main(void)
{
    string str("MCMXCIV");
    Solution s;
    cout << "resoult: " << s.romanToInt(str) << endl;

    return 0;
}

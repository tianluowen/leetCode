// date: 2020-05-30
// desc: count-and-say数列的前几项如下：
//       1, 11, 21, 1211, 111221, ...
//       1读作“1个1”或11
//       11读作“2个1“或者21
//       21读作”1个2，1个1“或者1211
//       给出一个整数n，请给出序列的第n项
//       注意：序列中的数字用字符串表示

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string perstr("1");
        string result("1");

        // 依次迭代
        while (--n)
        {
            perstr = result;
            result = "";
            int perchar = perstr[0];
            int count = 1;
            for (int i = 1; i < perstr.size(); i++)
            {
                // 当前字符不等于上一个字符，添加上次统计，初始化新的统计
                if (perstr[i] != perchar)
                {
                    result += ('0' + count);
                    result +=  perchar;  

                    count = 1;  
                    perchar =  perstr[i];   
                }
                else // 计数加 1
                {
                    count++;
                }
            }

            // 添加最后一次统计
            result += ('0' + count);
            result +=  perchar;  
        }

        return result;
    }
};

int main(void)
{
    Solution s;

    int n = 5;

    string result = s.countAndSay(n);
    
    cout << "input n = " << n << endl;
    cout << "result = " << result << endl;

    return 0;
}

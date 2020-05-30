// date: 2020-05-30
// desc: 「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：
//       1.     1
//       2.     11
//       3.     21
//       4.     1211
//       5.     111221
//       1 被读作  "one 1"  ("一个一") , 即 11。
//       11 被读作 "two 1s" ("两个一"）, 即 21。
//       21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
//       给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
//       注意：整数序列中的每一项将表示为一个字符串。

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

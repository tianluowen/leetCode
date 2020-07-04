// date: 2020-07-04
// desc: 题目描述
//       输入一行字符，分别统计出包含英文字母、空格、数字和其它字符的个数。

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str;
    while (getline(cin, str))
    {
        int letter = 0;
        int space = 0;
        int number = 0;
        int other = 0;
        
        for (int i = 0; i < str.size(); i++)
        {
            if ( '0' <= str[i] && str[i] <= '9')
            {
                number++;
            }
            else if (str[i] == ' ')
            {
                space++;
            }
            else if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z'))
            {
                letter++;
            }
            else
            {
                other++;
            }
        }
        
        cout << letter << endl;
        cout << space << endl;
        cout << number << endl;
        cout << other << endl;
    }
        
    return 0;
}

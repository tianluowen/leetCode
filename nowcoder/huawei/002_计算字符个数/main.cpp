// date: 2020-06-15
// desc: 写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
//       输入描述:
//       第一行输入一个有字母和数字以及空格组成的字符串，第二行输入一个字符。
//       输出描述:
//       输出输入字符串中含有该字符的个数。

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int countCharInStr(string str, char ch)
    {
        int count = 0;
        char tempch;
        
        ch >= 97 ? tempch = ch - 32 : tempch = ch + 32;
        
        for (int index = 0; index < str.size(); index++)
        {
            if (str[index] == ch || str[index] == tempch)
                count++;
        }
        
        return count;
    }
};


int main(void)
{
    string str;
    char ch;
    int count;
    
    getline(cin, str);
    cin >> ch;
    
    Solution s;
    
    count = s.countCharInStr(str, ch);
    
    
    cout << count << endl;
    
    return 0;
}

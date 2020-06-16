// date: 2020-06-16
// desc: 写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。（多组同时输入 ）
//       输入描述:
//       输入一个十六进制的数值字符串。
//       输出描述:
//       输出该数值的十进制字符串。

#include <iostream>
#include <string>

using namespace std;

int chartonum(char ch)
{
    if (ch >= 48 && ch <= 57)
        return ch - '0';
    else if (ch >= 65 && ch <= 70)
        return ch - 'A' + 10;
    else 
        return ch - 'a' + 10;
}

int main(void)
{
    string str;
    while (getline(cin, str))
    {
        int num = 0;
        
        for (int i = 2; i < str.size(); i++)
        {
            int temp = chartonum(str[i]);
            num  = num * 16+ temp;
        }
        
        cout << num << endl;
    }
    
    return 0;
}

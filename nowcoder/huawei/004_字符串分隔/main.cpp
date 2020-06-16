// date: 2020-06-16
// desc: •连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
//       •长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
//       输入描述:
//       连续输入字符串(输入2次,每个字符串长度小于100)
//       输出描述:
//       输出到长度为8的新字符串数组
//       示例1
//       输入
//       复制
//       abc
//       123456789
//       输出
//       复制
//       abc00000
//       12345678
//       90000000

#include <iostream>

using namespace std;

int main(void)
{
    while (!cin.eof())
    {
        string str;
        getline(cin, str);
        
        int i = 0;
        for (i = 0; i < str.size(); i++)
        {
            cout << str[i];
            if ((i+1) % 8 == 0)
                cout << endl;
        }
        
        if (i % 8 != 0)
        {
            for (int i = str.size() % 8; i < 8; i++)
                cout << '0';
            
            cout << endl;
        }
    }
    return 0;
}

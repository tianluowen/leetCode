// date: 2020-06-30
// desc: 题目描述
//       原理：ip地址的每段可以看成是一个0-255的整数，把每段拆分成一个二进制形式组合起来，然后把这个二进制数转变成
//       一个长整数。
//       举例：一个ip地址为10.0.3.193
//       每段数字             相对应的二进制数
//       10                   00001010
//       0                    00000000
//       3                    00000011
//       193                  11000001
//       组合起来即为：00001010 00000000 00000011 11000001,转换为10进制数就是：167773121，即该IP地址转换后的数字就是它了。
//       的每段可以看成是一个0-255的整数，需要对IP地址进行校验

//       输入描述:
//       输入 
//       1 输入IP地址
//       2 输入10进制型的IP地址
//       输出描述:
//       输出
//       1 输出转换成10进制的IP地址
//       2 输出转换后的IP地址


#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string ipstr;
    unsigned int num1, num2, num3, num4, num;
    char ch;
    unsigned int result;
    
    while (cin >> num1 >> ch >> num2 >> ch >> num3 >> ch >> num4 >> num)
    {
        result = 0;
        result += (num1 << 24) + (num2 << 16) + (num3 << 8) + num4;
        
        num1 = (num >> 24) & 255;
        num2 = (num >> 16) & 255;
        num3 = (num >> 8) & 255;
        num4 = num & 255;
        
        cout << result << endl;
        cout << num1 << '.' << num2 << '.' << num3 << '.' << num4 << endl;
    }
    
    return 0;
}

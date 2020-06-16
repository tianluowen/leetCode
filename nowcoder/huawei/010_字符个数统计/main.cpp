// date: 2020-06-16
// desc: 题目描述
//       编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)，换行表示结束符，不算在字符里。不在范围内的不作统计。注意是不同的字符
//       输入描述:
//       输入N个字符，字符在ACSII码范围内。
//       输出描述:
//       输出范围在(0~127)字符的个数。

#include <iostream>

using namespace std;

int main(void)
{
    char ch;
    int counts[128] = {0};
    int count = 0;
    
    while (cin >> ch)
    {
        if (ch == '\n')
            continue;
        else if (ch >= 0 || ch <= 127)
            counts[ch] = 1;
    }
    
    for (int i = 0; i < 128; i++)
    {
        count += counts[i];
    }
    
    cout << count << endl;
    
    return 0;
}

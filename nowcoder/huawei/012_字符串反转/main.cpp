// date: 2020-06-17
// desc: 写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）
//       输入描述:
//       输入N个字符
//       输出描述:
//       输出该字符串反转后的字符串

#include <iostream>

using namespace std;

int main(void)
{
    string str;
    char tempch;
    cin >> str;
    
    for (int left = 0, right = str.size() - 1; left < right; left++, right--)
    {
        tempch = str[left];
        str[left] = str[right];
        str[right] = tempch;
    }
    
    cout << str << endl;
    
    return 0;
}

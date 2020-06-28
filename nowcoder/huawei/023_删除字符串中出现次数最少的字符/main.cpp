// date: 2020-06-28
// desc: 题目描述
//       实现删除字符串中出现次数最少的字符，若多个字符出现次数一样，则都删除。输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。
//       注意每个输入文件有多组输入，即多个字符串用回车隔开
//       输入描述:
//       字符串只包含小写英文字母, 不考虑非法输入，输入的字符串长度小于等于20个字节。
//       输出描述:
//       删除字符串中出现次数最少的字符后的字符串。
//       输入
//       abcdd
//       输出
//       dd


#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str;
    
    while (cin >> str)
    {
        int charCount[26] = { 0 };
        
        // 统计字符
        for (int i = 0; i < str.size(); i++)
        {
            charCount[str[i] - 'a']++;
        }
        
        // 找出最少的字符
        int minCount = charCount[str[0] - 'a'];
        for (int i = 0; i < 26; i++)
        {
            if (charCount[i] != 0 && charCount[i] < minCount)
                minCount = charCount[i];
        }
        
        // 输出字符
        for (int i = 0; i < str.size(); i++)
        {
            if (charCount[str[i] - 'a'] != minCount)
            {
                cout << str[i];
            }
        }
        cout << endl;
        
    }
    
    return 0;
}

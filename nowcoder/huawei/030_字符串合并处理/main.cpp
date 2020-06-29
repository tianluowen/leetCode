// date: 2020-06-29
// desc: 题目描述
//       按照指定规则对输入的字符串进行处理。
//       详细描述：
//       将输入的两个字符串合并。
//       对合并后的字符串进行排序，要求为：下标为奇数的字符和下标为偶数的字符分别从小到大排序。这里的下标意思是字符在字符串中的位置。
//       对排序后的字符串进行操作，如果字符为‘0’——‘9’或者‘A’——‘F’或者‘a’——‘f’，则对他们所代表的16进制的数进行BIT倒序的操作，并转换为相应的大写字符。如字符为‘4’，为0100b，则翻转后为0010b，也就是2。转换后的字符为‘2’； 如字符为‘7’，为0111b，则翻转后为1110b，也就是e。转换后的字符为大写‘E’。
//       举例：输入str1为"dec"，str2为"fab"，合并为“decfab”，分别对“dca”和“efb”进行排序，排序后为“abcedf”，转换后为“5D37BF”

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const string helper1 = "0123456789abcdefABCDEF";
const string helper2 = "084C2A6E195D3B7F5D3B7F";

int main(void)
{
    string str;
    string str1;
    string str2;
    
    while (cin >> str1 >> str2)
    {
        str = str1 + str2;
        string sortstr1;
        string sortstr2;
        
        for (int i = 0; i < str.size(); i++)
        {
            if (i % 2 == 0)
                sortstr1 += str[i];
            else
                sortstr2 += str[i];
        }
        
        sort(sortstr1.begin(), sortstr1.end());
        sort(sortstr2.begin(), sortstr2.end());
        
        for (int i = 0; i < str.size(); i++)
        {
            if (i % 2 == 0)
                str[i] = sortstr1[i / 2];
            else
                str[i] = sortstr2[i / 2];
        }
        
        for (int i = 0; i < str.size(); i++)
        {
            int n = helper1.find(str[i]);
                if(n != -1)
                    str[i] = helper2[n];
        }
        
        cout << str << endl;
    }
    
    return 0;
}

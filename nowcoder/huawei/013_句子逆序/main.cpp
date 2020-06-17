// date: 2020-06-17
// desc: 将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
//       所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符
//       接口说明
//       输入描述:
//       将一个英文语句以单词为单位逆序排放。
//       输出描述:
//       得到逆序的句子

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str;
    
    getline(cin, str);
    
    //cout << str;
    
    
    for (int i = str.size() - 1; i >= 0; i--)
    {        
        if (i == 0)
        {
            int index;
            for (index = i; index < str.size(); index++)
            {
                if (str[index] == ' ')
                {
                    break;
                }
                cout << str[index];
            }
        }
        
        if (str[i] == ' ')
        {
            int index;
            for (index = i + 1; index < str.size(); index++)
            {
                if (str[index] == ' ')
                {
                    break;
                }
                cout << str[index];
            }
            cout << ' ';
        }
    }
    
    cout << endl;
    
    return 0;
}

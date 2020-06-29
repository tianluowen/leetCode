// date: 2020-06-29
// desc: 题目描述
//       1、对输入的字符串进行加解密，并输出。
//       2加密方法为：
//       当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写,如字母a时则替换为B；字母Z时则替换为a；
//       当内容是数字时则把该数字加1，如0替换1，1替换2，9替换0；
//       其他字符不做变化。
//       3、解密方法为加密的逆过程。
//       接口描述：
//       实现接口，每个接口实现1个基本操作：
//       void Encrypt (char aucPassword[], char aucResult[])：在该函数中实现字符串加密并输出
//       说明：
//       1、字符串以\0结尾。
//       2、字符串最长100个字符。
//       int unEncrypt (char result[], char password[])：在该函数中实现字符串解密并输出
//       说明：
//       1、字符串以\0结尾。
//       2、字符串最长100个字符。


#include <iostream>
#include <string>

using namespace std;

const char dirt1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const char dirt2[] = "BCDEFGHIJKLMNOPQRSTUVWXYZAbcdefghijklmnopqrstuvwxyza1234567890";



void Encrypt(string aucPassword, char aucResult[])
{
    int i;
    for (i = 0; i < aucPassword.size(); i++)
    {
        int j;
        for (j = 0; j < 62; j++)
        {
            if (aucPassword[i] == dirt1[j])
            {
                aucResult[i] = dirt2[j];
                break;
            }
        }
        
        if (j == 62)
            aucResult[i] = aucPassword[i];
    }
    
    aucResult[i] = '\0';
}

void unEncrypt(string result, char password[])
{
    int i;
    for (i = 0; i < result.size(); i++)
    {
        int j;
        for (j = 0; j < 62; j++)
        {
            if (result[i] == dirt2[j])
            {
                password[i] = dirt1[j];
                break;
            }
        }
        
        if (j == 62)
            password[i] = result[i];
    }
    
    password[i] = '\0';
}

int main(void)
{
    string str;
    string str2;
    char result[110]; 
    char result2[110]; 
    
    while (cin >> str >> str2)
    {
        Encrypt(str, result);
        cout << result << endl;
        unEncrypt(str2, result2);
        cout << result2 << endl;
    }    
    
    return 0;
}

// date: 2020-06-28
// desc: 题目描述
//       密码要求:
//       1.长度超过8位
//       2.包括大小写字母.数字.其它符号,以上四种至少三种
//       3.不能有相同长度大于等于2的子串重复
//       输入描述:
//       一组或多组长度超过2的子符串。每组占一行
//       输出描述:
//       如果符合要求输出：OK，否则输出NG


#include <iostream>
#include <string>

using namespace std;

bool is_passwd(string str)
{
    if (str.size() <= 8)
        return false;
    
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 48 && str[i] <= 57)
        {
            count++;
            break;
        }
    }
    
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 65 && str[i] <= 91)
        {
            count++;
            break;
        }
    }
    
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 97 && str[i] <= 123)
        {
            count++;
            break;
        }
    }
    
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 65 && str[i] <= 88 || 
           str[i] >= 97 && str[i] <= 123 || 
            str[i] >= 65 && str[i] <= 9
           )
        {
            continue;
        }
        else
        {
            count++;
            break;
        }
    }
    
    if (count < 3)
        return false;
    
    for (int i = 0; i < str.size() - 2; i += 3)
    {
        string temp = str.substr(i, 3);
        string temp2 = str.substr(i + 3, str.size() - i - 3);
        
        if (temp2.find(temp) != std::string::npos)
            return false;
    }
    
    for (int i = 1; i < str.size() - 2; i += 3)
    {
        string temp = str.substr(i, 3);
        string temp2 = str.substr(i + 3, str.size() - i - 3);
        
        if (temp2.find(temp) != std::string::npos)
            return false;
    }
    
    for (int i = 2; i < str.size() - 2; i += 3)
    {
        string temp = str.substr(i, 3);
        string temp2 = str.substr(i + 3, str.size() - i - 3);
        
        if (temp2.find(temp) != std::string::npos)
            return false;
    }
    
    
    return true;
}

int main(void)
{
    string str;
    while (cin >> str)
    {
        if (is_passwd(str))
            cout << "OK" << endl;
        else
            cout << "NG" << endl;
    }
    
    return 0;
}

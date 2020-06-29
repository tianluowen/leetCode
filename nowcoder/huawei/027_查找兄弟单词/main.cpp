// date: 2020-06-29
// desc: 题目描述
//       输入描述:
//       先输入字典中单词的个数，再输入n个单词作为字典单词。
//       输入一个单词，查找其在字典中兄弟单词的个数
//       再输入数字n
//       输出描述:
//       根据输入，输出查找到的兄弟单词的个数
//       示例1
//       输入
//       3 abc bca cab abc 1
//       输出
//       2
//       bca


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int judge(string findString, string v)
{
    sort(findString.begin(), findString.end());
    sort(v.begin(), v.end());
    if(findString == v)
        return 1;
    else
        return 0;
}

int main(void)
{
    int countnum;
    
    while (cin >> countnum)
    {
        vector<string> words;
        vector<string> brother;
        string word;
        int pos;
        
        while (countnum--)
        {
            string tempstr;
            cin >> tempstr;
            words.push_back(tempstr);
        }
        cin >> word;
        cin >> pos;
        
        for (int i = 0; i < words.size(); i++)
        {
            if (word != words[i] && judge(word, words[i]))
            {
                brother.push_back(words[i]);
            }
        }
        
        sort(brother.begin(), brother.end());
        
        cout << brother.size() << endl;
        
        if (pos <= brother.size())
            cout << brother[pos - 1] << endl;
        
    }
    
    return 0;
}

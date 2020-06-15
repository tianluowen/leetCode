// date: 2020-06-15
// desc: 计算字符串最后一个单词的长度，单词以空格隔开。
//       输入描述:
//       一行字符串，非空，长度小于5000。
//       输出描述:
//       整数N，最后一个单词的长度。

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int lastWordLength(string str)
    {
        int count = 0;
        for (int index = 0; index < str.size(); index++)
        {
            // 遇到空格重置
            if (str[index] == ' ')
                count = 0;
            else
                count++;
        }
        
        return count;
    }
};

int main(void)
{
    Solution s;
    string strin;
    
    //  接受输入
    getline(cin, strin);
    
    // 调用求结果
    int countLastStr = s.lastWordLength(strin);
    
    // 输出
    cout << countLastStr << endl;
    
    return 0;
}

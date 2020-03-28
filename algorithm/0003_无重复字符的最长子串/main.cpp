// date: 2020-03-28
// desc: 无重复字符的最长子串

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string str;
        int i = 0;
        int maxLeng = 0;
        char ch = 'a';
        int delpos = 0;
        int length = 0;

        while (s[i] != '\0')
        {
            ch = s[i];
            delpos = str.find(ch);

            if (delpos >= 0)
                str = str.erase(0, delpos + 1);

            str.push_back(ch);
            length = str.length();
            if (length > maxLeng)
                maxLeng = length;

            i++;
        }  
        return maxLeng;     
    }
};

int main(void)
{
    Solution s;
    string str("abcdabcd");
    int a = s.lengthOfLongestSubstring(str);

    cout << "str = " << str << "\nlengthoflonggetsubstring = " << a << endl;

    return 0;
}

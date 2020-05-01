// date: 2020-05-01
// desc: 最长回文子串

#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int i = 0;
        int length = 0;
        int maxlength = 0;
        int pre = 0;
        int next = 0;
        int indexbegin = 0;
        while (s[i] != '\0')
        {
            // aba 形式
            pre = i - 1;
            next = i + 1;
            length = 1;
            while (pre >= 0 && s[next] != '\0')
            {
                if (s[pre] == s[next])
                {
                    length += 2;
                    pre--;
                    next++;
                }
                else
                {
                    break;
                }
            }
            if (length > maxlength)
            {
                maxlength = length;
                indexbegin = pre + 1;
            }

            // abba 形式 
            if (i + 1 < s.length() && s[i] == s[i+1] )
            {
                pre = i - 1;
                next = i + 2;
                length = 2;
                while (pre >= 0 && s[next] != '\0')
                {
                    if (s[pre] == s[next])
                    {
                        length += 2;
                        pre--;
                        next++;
                    }
                    else
                    {
                        break;
                    }
          
                }
                if (length > maxlength)
                {
                    maxlength = length;
                    indexbegin = pre + 1;
                }
            }
            i++;
        }

        return s.substr(indexbegin, maxlength);
    }
};


int main(void)
{
    Solution s;

    cout << "\"babad\"\n" << "\"" << s.longestPalindrome("babad") << "\"\n";

    return 0;
}

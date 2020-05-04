// date: 2020-05-04
// desc: 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配

#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        // return regex_match(s, regex(p));

        if (s.length() == 0 && p.length() == 0)
            return true;
        
        bool match = (s.length() > 0 && (s[0] == p[0] || p[0] == '.'));
        if (p.length() > 1 && p[1] == '*')
        {
            return isMatch(s, p.substr(2)) || (match && isMatch(s.substr(1), p));
        } 
        else 
        {
            return match && isMatch(s.substr(1), p.substr(1));
        }
    }
};

int main(void)
{
    Solution s;

    cout << "s = aab, p = a*b" << endl;
    cout << boolalpha << s.isMatch("aab", "a*b") << endl;

    return 0;
}

// date: 2020-05-12
// desc: 请实现支持'.'and'*'.的通配符模式匹配

#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        
        if(*p == '\0') {
            return *s == '\0';
        }
        
        bool match = (*s && (*s == *p || *p == '.'));

        if(*(p + 1) && *(p + 1) == '*') {
            return isMatch(s, p + 2) || (match && isMatch(s + 1, p));
        }
        else {
            return match && isMatch(s + 1, p + 1);
        }
    }
};
          

int main(void)
{
    Solution s;
    bool result = s.isMatch("aab", "c*a*b");

    cout << "s = aab, p = c*a*b" << endl;
    cout << "result = " << boolalpha << result << endl;

    return 0;
}

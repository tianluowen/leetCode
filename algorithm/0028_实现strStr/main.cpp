// date: 2020-05-17
// desc: 实现 strStr() 函数。
//       给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // needle 为空 返回 0
        if (needle.size() == 0)
            return needle.size();
        
        int haystack_size = haystack.size();
        int needle_size = needle.size();

        // 依次判断
        for (int i = 0; i <= haystack_size - needle_size; i++)
        {
            int j = 0;
            while (haystack[i++] == needle[j++])
            {
                if (j == needle_size)
                    return i - j;
            }

            // i 的位置回溯
            i = i - j;
        }

        // 找不到返回 -1
        return -1;
    }
};

int main(void)
{
    Solution s;
    string haystack("hello");
    string needle("ll");

    int result = s.strStr(haystack, needle);

    cout << "haystack = \"" << haystack << "\", needle = \"" << needle << "\"" << endl;

    cout << "index = " << result << endl;

    return 0;
}

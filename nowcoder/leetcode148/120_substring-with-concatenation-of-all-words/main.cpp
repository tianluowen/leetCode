// date: 2020-05-21
// desc: 给出一个字符串S和一组单词L，L中单词的长度都相等，找出S中的符合以下要求的子串在S中的起始位置索引：子串为L中所有单词串联在一起(单词的顺序随意)，L中的每个单词只出现一次，中间不能有其他的字符。
//       例如：给定S="barfoothefoobarman"，L为["foo", "bar"]，
//       返回的索引应该是[0,9].（不用关心给出索引的顺序）

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // s 为空 或者 words 为空，直接返回 空
        if (s.size() == 0 || words.size() == 0)
            return vector<int> {};

        unordered_map<string, int> word;      // 存放 words 中的 所有 word
        unordered_map<string, int> findword;  // 存放 已经找到到的 word
        vector<int> result;                   // 存放 所有返回结果

        // 将 words 中的单词 按数量记录到 word 中
        for (auto val : words)
        {
            if (word.find(val) == word.end())
                word[val] = 1;
            else
                word[val]++;
        }

        // 滑动窗口，只遍历 i -> wordlen 的之间的位置
        int wordlen = words[0].size();
        for (int i = 0; i < wordlen; i++)
        {
            // 清空上次查找到的 字符串
            findword.clear();

            // 当 s left 后面的长度 < 整个 words 所有字符的长度时，就不用遍历了
            int left = i;
            int right = left;
            while (left <= (int)(s.size() - wordlen * words.size()))
            {
                // 取出这次要判读的 字符串
                string tempstr = s.substr(right, wordlen);
                // 当前字符串没有查找到，清空 findword 从新开始
                if (word.find(tempstr) == word.end())
                {    
                    findword.clear();            
                    left = right + wordlen;
                    right = left;
                }
                else
                {
                    // 添加到查找记录中
                    findword[tempstr]++;

                    // 如果该单词数量超过 words 中的，则清除 left 到 第一次出现该 words 的所有 字符串
                    if (findword[tempstr] > word[tempstr])
                    {
                        // 改变位置
                        int find = s.find(tempstr, left);
                        while (left <= find)
                        {
                            findword[s.substr(left, wordlen)]--;
                            left += wordlen;
                        } 
                        right += wordlen;
                    }
                    else
                    {
                        // 如果满足要求了，添加结果，并删除最左边的一个 string 继续判断
                        if (findword == word)
                        {
                            result.push_back(left);
                            findword[s.substr(left, wordlen)]--;
                            left += wordlen;
                            right += wordlen;
                        }
                        else
                        {
                            right += wordlen;    
                        }
                    }
                }
            }
        }

        // return
        return result;
    }
};

int main(void)
{
    Solution s;
    string str("barfoothefoobarman");
    vector<string> words {"foo", "bar"};
    vector<int> result;

    result = s.findSubstring(str, words);

    cout << "str = \"" << str << "\"" << endl;
    cout << "words = [";
    for (int i = 0; i < words.size(); i++)
    {
        if (i != words.size() - 1)
        {
            cout << "\"" << words[i] << "\", "; 
        }
        else
        {
            cout << "\"" << words[i] << "\"]" << endl; 
        }
    }


    cout << "result = [";
    for (int i = 0; i < result.size(); i++)
    {
        if (i != result.size() - 1)
        {
            cout << result[i] << ", "; 
        }
        else
        {
            cout << result[i] << "]" << endl; 
        }
    }
    return 0;
}

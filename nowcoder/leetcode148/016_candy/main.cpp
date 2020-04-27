// date: 2020-04-27
// desc: 有N个小朋友站在一排，每个小朋友都有一个评分
//       你现在要按以下的规则给孩子们分糖果：
//         - 每个小朋友至少要分得一颗糖果
//         - 分数高的小朋友要他比旁边得分低的小朋友分得的糖果多
//      你最少要分发多少颗糖果？

#include <iostream>
#include <vector>

using namespace std;
        
class Solution {
public:
    int candy(vector<int> &ratings) {
        int length = ratings.size();
        int resultsum = 0;
        vector<int> result(length, 1);

        // 从左向右 
        for (int i = 1; i < length; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                result[i] = result[i - 1] + 1;
            }
        }
        
        // 从右向左
        for (int i = length - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1] && result[i] <= result[i + 1])
            {
                result[i] = result[i + 1] + 1;
            }
        }
        
         // 统计 输出
        for (auto num : result)
        {
            resultsum += num;
        }
        
        return resultsum;
    }
};
        
int main(void)
{
    Solution s;

    vector<int> A {2, 0, 1};

    int candy = s.candy(A);

    cout << "[2, 0, 1]" << endl;
    cout << "candy = " << candy << endl;


    return 0;
}

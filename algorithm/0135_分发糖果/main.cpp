// date: 2020-04-27
// desc: 老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
//       你需要按照以下要求，帮助老师给这些孩子分发糖果：
//         - 每个孩子至少分配到 1 个糖果。
//         - 相邻的孩子中，评分高的孩子必须获得更多的糖果。
//       那么这样下来，老师至少需要准备多少颗糖果呢？

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

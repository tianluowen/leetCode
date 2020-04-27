// date: 2020-04-27
// desc: 给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素

#include <iostream>
#include <vector>

using namespace std;
        
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0;
        int b = 0;
        int bit = 0;

        for (auto num : nums)
        {
            a ^= num;
        }

        // 取出 a 最右边为 1 的位 -a = ~a + 1;
        bit = a & (-a);
        for (auto num : nums)
        {
            // 只去 bit 为 1 的所有数据
            if (num & bit)
            {
                b ^= num;
            }
        }

        a = a ^ b;
        return {a, b};
    }
};
        
int main(void)
{
    Solution s;

    vector<int> A {1,2,1,3,2,5};
    vector<int> result;
    result = s.singleNumber(A);

    cout << "[1,2,1,3,2,5]" << endl;
    cout << "result = " << result[0] << ", " << result[1] << endl;

    return 0;
}

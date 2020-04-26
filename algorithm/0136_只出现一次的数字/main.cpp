// date: 2020-04-26
// desc: 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素

#include <iostream>
#include <vector>

using namespace std;
        
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (auto num : nums)
        {
            a ^= num;
        }

        return a;
    }
};
        
int main(void)
{
    Solution s;

    vector<int> A {2, 2, 1};
    int result = s.singleNumber(A);

    cout << "[2, 2, 1]" << endl;
    cout << "result = " << result << endl;

    return 0;
}

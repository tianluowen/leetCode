// date: 2020-04-26
// desc: 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素

#include <iostream>
#include <vector>

using namespace std;
        
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seen_once = 0;
        int seen_twice = 0;

        for (auto num : nums)
        {
            // cout << num << endl;
            // cout << "000   " << seen_once << "    " << seen_twice << endl;
            seen_once = ~seen_twice & (seen_once ^ num);
            // cout << "111   " << seen_once << "    " << seen_twice << endl;
            seen_twice = ~seen_once & (seen_twice ^ num);
            // cout << "222   " << seen_once << "    " << seen_twice << endl;
        }
        // cout << seen_once << "    " << seen_twice << endl;
        return seen_once;

    }
};
        
int main(void)
{
    Solution s;

    vector<int> A {2, 2, 1};
    int result = s.singleNumber(A);

    cout << "[2, 2, 2, 1]" << endl;
    cout << "result = " << result << endl;

    return 0;
}

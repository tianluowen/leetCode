// date: 2020-05-13
// desc: 给出一个有n个元素的数组S，S中是否有元素a,b,c满足a+b+c=0？找出数组S中所有满足条件的三元组。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();

        // 输入为空的时候
        if (nums.size() == 0)
            return result;

        // 排序
        sort(nums.begin(), nums.end());

        // 对每一个值进行检测
        for (int index = 0; index < size; index++)
        {
            // 两个值相同跳过
            if (index > 0 && nums[index] == nums[index - 1])
                continue;

            // 后面的所有数 > 0 直接返回结果
            if (nums[index] > 0)
                return result;
            
            // 取剩下两个数 按大小移动
            int left = index + 1;
            int right = size - 1;
            while (left < right)
            {
                int temp = nums[index] + nums[left] + nums[right];
                if (temp == 0)
                {
                    result.push_back({nums[index], nums[left], nums[right]});
                    // 相同的数字跳过，避免重复结果
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    
                    left++;
                    right--;
                }
                else if (temp < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return result;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result;
    
    result = s.threeSum(nums);

    cout << "[ -1, 0, 1, 2, -1, -4 ]" << endl;
    cout << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[ ";
        for (auto num : result[i])
            cout << num << " ";

        cout << "] ";
    }
    cout << endl;

    return 0;
}

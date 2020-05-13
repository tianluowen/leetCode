// date: 2020-05-13
// desc: 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int result;
        int size = nums.size();
        int min = INT_MAX;

        // 排序
        sort(nums.begin(), nums.end());

        // 挨个计算 要遍历
        for (int index = 0; index < size; ++index)
        {
            int left = index + 1;
            int right = size - 1;
            while (left < right)
            {
                int sum = nums[index] + nums[left] + nums[right];
                int temp = target -sum;
                if (temp == 0)
                    return target;
                else if (temp < 0)
                    temp = -temp;
                if (temp < min)
                {
                    min = temp;
                    result = sum;
                }
                temp = target -sum;
                if (temp < 0)
                    right--;
                else
                    left++;
            }
        }

        return result;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums {-1, 2, 1, -4};
    int result;
    
    result = s.threeSumClosest(nums, 1);

    cout << "[ -1, 2, 1, -4 ]" << endl;
    cout << "result = " << result << endl;

    return 0;
}

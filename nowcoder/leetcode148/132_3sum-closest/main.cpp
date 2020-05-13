// date: 2020-05-13
// desc: 给出含有n个整数的数组s，找出s中和加起来的和最接近给定的目标值的三个整数。返回这三个整数的和。你可以假设每个输入都只有唯一解。

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

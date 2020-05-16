// date: 2020-05-16
// desc: 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//       不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//       元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 数组为空
        if (nums.size() == 0)
            return 0;

        int i = 0; 
        int j = 0;
        int nums_size = nums.size();
        while (i < nums_size)
        {
            // 当不相等 且 i 不等于 j 时才赋值
            if (nums[i] != val)
            {
                if (i != j)
                    nums[j] = nums[i];

                j++;
            }
            i++;
        }
        
        return j;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums {3, 1, 2, 3, 4, 3};

    cout << "[";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i != nums.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "] remove = 3" << endl;

    int result = s.removeElement(nums, 3);

    cout << "[";
    for (int i = 0; i < result; i++)
    {
        cout << nums[i];
        if (i != result - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}

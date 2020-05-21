// date: 2020-05-21
// desc: 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
//       如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
//       必须原地修改，只允许使用额外常数空间。
//       以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
//       1,2,3 → 1,3,2
//       3,2,1 → 1,2,3
//       1,1,5 → 1,5,1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int max = nums[size - 1];

        for (int i = size - 1; i > 0; i--)
        {   
            // 记录比较过的最大的数据 
            if (nums[i - 1] >= max)
            {
                max = nums[i - 1];                
            }
            else
            {
                // 该位置上的值小于 右边的数字 排序，找到比该数字大的最小的数字换位
                sort(nums.begin() + i, nums.end());
                for (int j = i; j < size; j++)
                {
                    if (nums[j] > nums[i - 1])
                    {
                        int temp = nums[i - 1];
                        nums[i - 1] = nums[j];
                        nums[j] = temp;
                        return;
                    }
                }    
            }
        }
        
        // 重新排列为最小排列
        sort(nums.begin(), nums.end());
    }
};

int main(void)
{
    Solution s;
    vector<int> nums {1, 2, 3};

    cout << "nums = [";
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != nums.size() - 1)
        {
            cout << nums[i] << ", "; 
        }
        else
        {
            cout << nums[i] << "]" << endl; 
        }
    }

    s.nextPermutation(nums);

    cout << "result = [";
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != nums.size() - 1)
        {
            cout << nums[i] << ", "; 
        }
        else
        {
            cout << nums[i] << "]" << endl; 
        }
    }

    return 0;
}

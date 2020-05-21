// date: 2020-05-21
// desc: 实现函数next permutation（下一个排列）：将排列中的数字重新排列成字典序中的下一个更大的排列。将排列中的数字重新排列成字典序中的下一个更大的排列。
//       如果不存在这样的排列，则将其排列为字典序最小的排列（升序排列）
//       需要使用原地算法来解决这个问题，不能申请额外的内存空间
//       下面有机组样例，左边是输入的数据，右边是输出的答案
//       1,2,3→ 1,3,2
//       3,2,1→ 1,2,3
//       1,1,5→ 1,5,1

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

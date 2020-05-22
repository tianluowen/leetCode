// date: 2020-05-22
// desc: 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//       你的算法时间复杂度必须是 O(log n) 级别。
//       如果数组中不存在目标值，返回 [-1, -1]。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        int index = -1;

        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            
            if (nums[mid] == target)
            {
                index = mid;
                break;
            } 

            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        if (index == -1)
            return {-1, -1};
        
        int begin = index;
        int end = index;
        while (begin > 0 && nums[begin - 1] == nums[begin])
            begin--;
        while (end < nums.size() - 1 && nums[end] == nums[end + 1])
            end++;

        return {begin, end};
    }
};

int main(void)
{
    Solution s;
    vector<int> nums {5,7,7,8,8,10};
    int target = 8;

    vector<int> result = s.searchRange(nums, target);

    cout << "nums = [";
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != nums.size() - 1)
        {
            cout << nums[i] << ", "; 
        }
        else
        {
            cout << nums[i] << "]"; 
        }
    }
    cout << "  target = " << target << endl;

    cout << "result = [";
    for (int i = 0; i < result.size(); i++)
    {
        if (i != result.size() - 1)
        {
            cout << result[i] << ", "; 
        }
        else
        {
            cout << result[i] << "]"; 
        }
    }
    cout << endl;

    return 0;
}

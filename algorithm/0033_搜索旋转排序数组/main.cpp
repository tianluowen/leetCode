// date: 2020-05-22
// desc: 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//       ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
//       搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
//       你可以假设数组中不存在重复的元素。
//       你的算法时间复杂度必须是 O(log n) 级别。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 二分查找法，一个一定是有顺序的，一个没有。
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            
            if (nums[mid] == target)
                return mid;
            
            if (nums[left] <= nums[mid])
            {
                if (target >= nums[left] && target <= nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (target >= nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums {4,5,6,7,0,1,2};
    int target = 0;
    int result = s.search(nums, target);

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

    cout << "result = " << result << endl;

    return 0;
}

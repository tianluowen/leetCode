// date: 2020-05-19
// desc: 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int size = nums.size();

        int i;
        for (i = 0; i < size; i++)
        {
            if (nums[i] >= target)
                break;
        }

        return i;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums {1, 3, 5, 6};
    int target = 5;
    int result;
    
    result = s.searchInsert(nums, target);

    cout << "[ ";
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == nums.size() - 1)
            cout << nums[i] << " ]";
        else
            cout << nums[i] << ", ";
    }
    cout << ", target = " << target << endl;
    cout << "result = " << result << endl;

    return 0;
}

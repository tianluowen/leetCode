// date: 2020-05-24
// desc: 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int index = 0;
        int nums_size = nums.size();
        for (;index < nums_size; index++)
        {
            if (nums[index] > 0)
                break;
        }

        int count = 1;
        for (; index < nums_size; index++)
        {
            if (nums[index] != count) 
            {                
                if (index == 0 || nums[index] != nums[index - 1])

                 return count;
                
            }          
            else
                count++;         
        }

        return count;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums {1, 3, 5, 6};
    int result;
    
    result = s.firstMissingPositive(nums);

    cout << "[ ";
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == nums.size() - 1)
            cout << nums[i] << " ]";
        else
            cout << nums[i] << ", ";
    }
    cout << endl;
    cout << "result = " << result << endl;

    return 0;
}

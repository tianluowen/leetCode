// date: 2020-05-31
// desc: 给出一个无序的整数型数组，求不在给定数组里的最小的正整数
//       例如：
//       给出的数组为[1,2,0] 返回3,
//       给出的数组为[3,4,-1,1] 返回2.
//       你需要给出时间复杂度在O(n)之内并且空间复杂度为常数级的算法

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int* nums, int n) {
        // write code here
        sort(nums, nums + n);

        int index = 0;
        for (;index < n; index++)
        {
            if (nums[index] > 0)
                break;
        }

        int count = 1;
        for (; index < n; index++)
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
    int nums[] = {1, 3, 5, 6};
    int n = sizeof(nums) / sizeof(int);
    int result;
    
    result = s.firstMissingPositive(nums, n);

    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << nums[i] << " ]";
        else
            cout << nums[i] << ", ";
    }
    cout << endl;
    cout << "result = " << result << endl;

    return 0;
}

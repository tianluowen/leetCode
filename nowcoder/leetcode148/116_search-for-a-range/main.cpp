// date: 2020-05-22
// desc: 给出一个有序数组，请在数组中找出目标值的起始位置和结束位置
//       你的算法的时间复杂度应该在O(log n)之内
//       如果数组中不存在目标，返回[-1, -1].
//       例如：
//       给出的数组是[5, 7, 7, 8, 8, 10]，目标值是8,
//       返回[3, 4].

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param A int整型一维数组 
     * @param n int A数组长度
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> searchRange(int* A, int n, int target) {

        int left = 0;
        int right = n - 1;
        int index = -1;

        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            
            if (A[mid] == target)
            {
                index = mid;
                break;
            } 

            if (A[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        if (index == -1)
            return {-1, -1};
        
        int begin = index;
        int end = index;
        while (begin > 0 && A[begin - 1] == A[begin])
            begin--;
        while (end < n-  1 && A[end] == A[end + 1])
            end++;

        return {begin, end};
    }
};

int main(void)
{
    Solution s;
    int nums[] = {5,7,7,8,8,10};
    int target = 8;

    vector<int> result = s.searchRange(nums, sizeof(nums) / sizeof(int), target);

    cout << "nums = [";
    for (int i = 0; i < sizeof(nums) / sizeof(int); i++)
    {
        if (i != sizeof(nums) / sizeof(int) - 1)
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

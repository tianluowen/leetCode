// date: 2020-05-22
// desc: 给出一个转动过的有序数组，你事先不知道该数组转动了多少
//       (例如,0 1 2 4 5 6 7可能变为4 5 6 7 0 1 2).
//       在数组中搜索给出的目标值，如果能在数组中找到，返回它的索引，否则返回-1。
//       假设数组中不存在重复项。

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
     * @return int整型
     */
    int search(int* A, int n, int target) {
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            
            if (A[mid] == target)
                return mid;
            
            if (A[left] <= A[mid])
            {
                if (target >= A[left] && target <= A[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (target >= A[mid] && target <= A[right])
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
    int nums[] = {4,5,6,7,0,1,2};
    int target = 0;

    int result = s.search(nums, sizeof(nums) / sizeof(int), target);

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

    cout << "result = " << result << endl;

    return 0;
}

// date: 2020-05-22
// desc: 给出一个有序的数组和一个目标值，如果数组中存在该目标值，则返回该目标值的下标。如果数组中不存在该目标值，则返回如果将该目标值插入这个数组应该插入的位置的下标
//       假设数组中没有重复项。
//       下面给出几个样例：
//       [1,3,5,6], 5 → 2
//       [1,3,5,6], 2 → 1
//       [1,3,5,6], 7 → 4
//       [1,3,5,6], 0 → 0

#include <iostream>
#include <vector>

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
    int searchInsert(int* A, int n, int target) {
        int i = 0;
        for (; i < n; i++)
            if (A[i] >= target)
                break;

        return i;
    }
};

int main(void)
{
    Solution s;
    int nums[] = {1, 3, 5, 6};
    int target = 5;
    int result;
    
    result = s.searchInsert(nums, sizeof(nums) / sizeof(int), target);

    cout << "[ ";
    for (int i = 0; i < sizeof(nums) / sizeof(int); i++)
    {
        if (i == sizeof(nums) / sizeof(int) - 1)
            cout << nums[i] << " ]";
        else
            cout << nums[i] << ", ";
    }
    cout << ", target = " << target << endl;
    cout << "result = " << result << endl;

    return 0;
}

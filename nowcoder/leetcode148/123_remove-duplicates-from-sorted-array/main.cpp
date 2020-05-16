// date: 2020-05-16
// desc: 给定一个已排序的数组，使用就地算法将重复的数字移除，使数组中的每个元素只出现一次，返回新数组的长度。
//       不能为数组分配额外的空间，你必须使用常熟级空间复杂度的就地算法。
//       例如，
//       给定输入数组 A=[1,1,2]，
//       你给出的函数应该返回length=2，A数组现在是[1,2]。

#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // 长度小于等于 1 返回长度。不变
        if (n <= 1)
            return n;

        // 开始挨个处理
        int i = 1;
        int j = 0;
        while (i < n)
        {
            // 仅当 i 位置的数不等于 j位置的数，而且 i 比 j 大 1 时才移动
            if (A[i] != A[j])
            {
                if (i > j + 1)
                    A[++j] = A[i];
                else
                    j++;
            }            
            i++;
        }

        return j + 1;
    }
};

int main(void)
{
    Solution s;
    int nums[] = {1, 1, 2};

    cout << "[";
    for (int i = 0; i < 3; i++)
    {
        cout << nums[i];
        if (i != 2)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    int result = s.removeDuplicates(nums, sizeof(nums) / sizeof(int));

    cout << "[";
    for (int i = 0; i < result; i++)
    {
        cout << nums[i];
        if (i != result - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}

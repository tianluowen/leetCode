// date: 2020-05-16
// desc: 给定一个数组和一个值，使用就地算法将数组中所有等于这个值的元素删除，并返回新数组的长度。
//       元素的顺序可以更改。你不用去关心大于当前数组长度的空间里面存储的值


#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // 数组为空
        if (n == 0)
            return 0;

        int i = 0; 
        while (i < n)
        {
            // 当不相等 且 i 不等于 j 时才赋值
            if (A[i] == elem)
            {
                if (i == n -1)
                {
                    n--;
                }
                else
                {
                    A[i] = A[n - 1];
                    n--;
                }
                   
            }
            else
            {
                i++;
            }
        }
        
        return n;
    }
};

int main(void)
{
    Solution s;
    int nums[] = {3, 1, 2, 3, 4, 3};

    cout << "[";
    for (int i = 0; i < sizeof(nums) / sizeof(int); i++)
    {
        cout << nums[i];
        if (i != sizeof(nums) / sizeof(int) - 1)
        {
            cout << ", ";
        }
    }
    cout << "] remove = 3" << endl;

    int result = s.removeElement(nums, sizeof(nums) / sizeof(int), 3);

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

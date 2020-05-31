// date: 2020-05-31
// desc: 给出n个数字，表示一个高程图，高程图中每一条的宽度为1，请计算下雨之后这个地形可以存储多少水
//       例如
//       给出[0,1,0,2,1,0,1,3,2,1,2,1],返回6.

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
     * @return int整型
     */
    int trap(int* A, int n) {
        if (n < 3)
            return 0;

        // 找出最大的数字
        int maxnum = 0;
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] >= maxnum)
            {
                maxnum = A[i];
                index = i;
            }
        }

        // 计算从左到最大数存的雨水
        int sum = 0;
        int currt = A[0];
        for (int i = 1; i <= index; i++)
        {
            if (A[i] >= currt)
            {
                currt = A[i];
                continue;
            }
            else
            {
                sum += (currt - A[i]);
            }
        }

        // 计算从右到最大值
        currt = A[n - 1];
        for (int i = n - 2; i >= index; i--)
        {
            if (A[i] >= currt)
            {
                currt = A[i];
                continue;
            }
            else
            {
                sum += (currt - A[i]);
            }
        }

        return sum;
    }
};

int main(void)
{
    Solution s;
    int nums[] {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result;
    int n = sizeof(nums) / sizeof(int);
    
    result = s.trap(nums, n);

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

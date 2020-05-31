// date: 2020-05-31
// desc: 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//       输入: [0,1,0,2,1,0,1,3,2,1,2,1]
//       输出: 6

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
            return 0;

        // 找出最大的数字
        int maxnum = 0;
        int index = 0;
        for (int i = 0; i < height.size(); i++)
        {
            if (height[i] >= maxnum)
            {
                maxnum = height[i];
                index = i;
            }
        }

        // 计算从左到最大数存的雨水
        int sum = 0;
        int currt = height[0];
        for (int i = 1; i <= index; i++)
        {
            if (height[i] >= currt)
            {
                currt = height[i];
                continue;
            }
            else
            {
                sum += (currt - height[i]);
            }
        }

        // 计算从右到最大值
        currt = height[height.size() - 1];
        for (int i = height.size() - 2; i >= index; i--)
        {
            if (height[i] >= currt)
            {
                currt = height[i];
                continue;
            }
            else
            {
                sum += (currt - height[i]);
            }
        }

        return sum;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result;
    
    result = s.trap(nums);

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

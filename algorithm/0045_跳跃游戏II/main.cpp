// date: 2020-06-04
// desc: 给定一个非负整数数组，你最初位于数组的第一个位置。
//       数组中的每个元素代表你在该位置可以跳跃的最大长度。
//       你的目标是使用最少的跳跃次数到达数组的最后一个位置。
//       示例:
//       输入: [2,3,1,1,4]
//       输出: 2
//       解释: 跳到最后一个位置的最小跳跃数是 2。
//            从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        
        int start      = 0;
        int end        = 1;
        int count      = 0;
        int maxNextPos = 0;

        while (end < nums.size())
        {
            for (int index = start; index < end; index++)
            {
                maxNextPos = max(nums[index] + index, maxNextPos);
            }
            cout << "test end = " << end << endl;
            start = end;
            end = maxNextPos + 1;
            count++;
        }

        return count;
    }
};
*/

class Solution {
public:
    // 理解题意思，nums[0] = 3;  意思是 从 0 开始下一步可以最远跳转到下标为 3 的位置
        int jump(vector<int>& nums) {
        int start      = 0;
        int end        = 0;
        int maxNextPos = 0;
        int count      = 0;
        int nums_leng = nums.size();

        for (int index = 0; index < nums_leng - 1; index++)
        {
            maxNextPos = max(maxNextPos, nums[index] + index);
            if (index == end)
            {
                end = maxNextPos;
                count++;
            }
        }

        return count;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums {2, 3, 1, 1, 4};

    int result = s.jump(nums);

    cout << "nums = [";
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != nums.size() - 1)
        {
            cout << nums[i] << ", "; 
        }
        else
        {
            cout << nums[i] << "]"; 
        }
    }
    cout << endl << endl;

    cout << "result = " << result << endl;

    return 0;
}

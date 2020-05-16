// date: 2020-05-16
// desc: 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
//       k 是一个正整数，它的值小于或等于链表的长度。
//       如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 长度小于等于 1 返回长度。不变
        if (nums.size() <= 1)
            return nums.size();

        // 开始挨个处理
        int i = 1;
        int j = 0;
        while (i < nums.size())
        {
            // 仅当 i 位置的数不等于 j位置的数，而且 i 比 j 大 1 时才移动
            if (nums[i] != nums[j])
            {
                if (i > j + 1)
                    nums[++j] = nums[i];
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
    vector<int> nums {1, 1, 2};

    cout << "[";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i != nums.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    int result = s.removeDuplicates(nums);

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

// date: 2020-06-09
// desc: 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
//       示例:
//       输入: [1,2,3]
//       输出:
//       [
//         [1,2,3],
//         [1,3,2],
//         [2,1,3],
//         [2,3,1],
//         [3,1,2],
//         [3,2,1]
//       ]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;     // 存储所有的结果
    vector<int> tempnum;            // 存放每一次生成列表的数据
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // 递归调用
        mute(nums);

        return result;
    }

    void mute(vector<int>& nums)
    {
        // 如果列表中已经没有数据 则存入 result 结束递归
        if (nums.size() == 0)
        {
            result.push_back(tempnum);
            return;
        }

        // 依次遍历，调用下次递归
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0)
            {
                tempnum.pop_back();
            }
            tempnum.push_back(nums[i]);
            vector<int> temp = nums;
            // 删除本次使用的元素，继续递归排列
            temp.erase(temp.begin() + i);
            mute(temp);
        }
        
        // 删除本阶段添加的数据，返回上依次
        tempnum.pop_back(); 
    }
};

int main(void)
{
    Solution s;
    vector<int> nums {1, 2, 3};

    vector<vector<int>> result = s.permute(nums);

    cout << "[";
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

    cout << "[" << endl;
    vector<int> data;
    for (int i = 0; i < result.size(); i++)
    {
        data = result[i];
        cout << "  [";
        for (int j = 0; j < data.size(); j++)
        {
            if (j == data.size() - 1)
            {
                cout << data[j] << "]";
                if (i != result.size() - 1)
                {
                    cout << "," << endl;
                }
                else
                {
                    cout << endl;
                }
            }
            else
            {
                cout << data[j] << ", ";
            }
        }
    }
    cout << "]" << endl;

    return 0;
}

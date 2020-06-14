// date: 2020-06-14
// desc: 给出一组可能包含重复项的数字，返回该组数字的所有排列
//       例如；
//       [1,1,2]的排列如下：
//       [1,1,2],[1,2,1], [2,1,1].

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;     // 存储所有的结果
    vector<int> tempnum;            // 存放每一次生成列表的数据
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 对输入排序，方便去重
        sort(nums.begin(), nums.end());

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
            // 相等的数跳过
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

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
    vector<int> nums {1, 1, 2};

    vector<vector<int>> result = s.permuteUnique(nums);

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

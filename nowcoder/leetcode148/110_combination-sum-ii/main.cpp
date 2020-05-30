// date: 2020-05-30
// desc: 给出一组候选数C和一个目标数T，找出候选数中起来和等于T的所有组合。
//       C中的每个数字在一个组合中只能使用一次。
//       注意：
//       题目中所有的数字（包括目标数T）都是正整数
//       组合中的数字 (a 1, a 2, … , a k) 要按非递增排序 (ie, a 1 ≤ a 2 ≤ … ≤ a k).
//       结果中不能包含重复的组合
//       例如：给定的候选数集是[10,1,2,7,6,1,5]，目标数是8
//       解集是：
//       [1, 7]
//       [1, 2, 5]
//       [2, 6]
//       [1, 1, 6]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> tempresult;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        combinationAll(candidates, target, 0);

        return result;
    }

    void combinationAll(vector<int>& temp, int sum, int index)
    {
        // 找到一组结果
        if (sum == 0)
        {
            result.push_back(tempresult);
            return;
        }
        else if (sum < 0)  // 没找到
        {
            return;
        }
        else
        {
            // 依次取出一个数 递归
            for (int i = index; i < temp.size(); i++)
            {
                if (i > index && temp[i] == temp[i - 1])
                    continue;
                if (i != index)
                {
                    // 修改本次使用的 数
                    tempresult.pop_back();
                }
                tempresult.push_back(temp[i]);

                vector<int> tempCanidates = temp;
                tempCanidates.erase(tempCanidates.begin() + i);
                combinationAll(tempCanidates, sum - temp[i], i);
            }
            
            // 回溯 返回
            if (index < temp.size())
                tempresult.pop_back();
            return;
        }
    }
};

int main(void)
{
    Solution s;
    vector<int> nums {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result;
    
    result = s.combinationSum2(nums, target);

    cout << "[ ";
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == nums.size() - 1)
            cout << nums[i] << " ]";
        else
            cout << nums[i] << ", ";
    }
    cout << ", target = " << target << endl;

    // cout result
    cout << endl << "[" << endl;
    for (int index = 0; index < result.size(); index++)
    {
        auto data = result[index];
        cout << "   [";
        for (int i = 0; i < data.size(); i++)
        {
            if (i == data.size() - 1)
                cout << data[i];
            else
                cout << data[i] << ", ";
        }
        if (index == result.size() - 1)
            cout << "]" << endl;
        else
            cout << "]," << endl;
    }
    cout << "]" << endl;

    return 0;
}

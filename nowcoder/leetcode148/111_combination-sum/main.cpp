// date: 2020-05-30
// desc: 给出一组候选数C和一个目标数T，找出候选数中加起来和等于T的所有组合。
//       C中的数字在组合中可以被无限次使用
//       注意：
//       题目中所有的数字（包括目标数T）都是正整数
//       你给出的组合中的数字 (a 1, a 2, … , a k) 要按非递增排序 (ie, a 1 ≤ a 2 ≤ … ≤ a k).
//       结解集中不能包含重复的组合
//       例如：给定的候选数集是[2,3,6,7]，目标数是7
//       解集是：
//       [7]
//       [2, 2, 3]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> tempCanidates;
    vector<vector<int>> result;
    vector<int> tempresult;

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        tempCanidates = candidates;
        sort(tempCanidates.begin(), tempCanidates.end());

        combinationAll(target, 0);

        return result;
    }

    void combinationAll(int sum, int index)
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
            for (int i = index; i < tempCanidates.size(); i++)
            {
                if (i != index)
                {
                    // 修改本次使用的 数
                    tempresult.pop_back();
                }
                tempresult.push_back(tempCanidates[i]);

                combinationAll(sum - tempCanidates[i], i);
            }

            // 回溯 返回
            tempresult.pop_back();
        }
    }
};

int main(void)
{
    Solution s;
    vector<int> nums {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result;
    
    result = s.combinationSum(nums, target);

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

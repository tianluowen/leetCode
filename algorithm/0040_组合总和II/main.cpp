// date: 2020-05-30
// desc: 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//       candidates 中的每个数字在每个组合中只能使用一次。
//       说明：
//       所有数字（包括目标数）都是正整数。
//       解集不能包含重复的组合。

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

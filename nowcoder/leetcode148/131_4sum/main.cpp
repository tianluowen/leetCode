// date: 2020-05-14
// desc: 给出一个有n个元素的数组S，S中是否有元素a,b,c和d满足a+b+c+d=目标值？找出数组S中所有满足条件的四元组。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        vector<vector<int>> result;
        int size = nums.size();

        sort(nums.begin(), nums.end());

        for (int first = 0; first < size - 3; ++first)
        {
            
            // 当前循环最小的可能
            if ((nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3]) > target)
                break; // 注意这个是 break  没有比这个更小的可能了
            // 当前循环下最大的可能
            if ((nums[first] + nums[size - 1] + nums[size + -2] + nums[size - 3]) < target)
                continue; // 移动 sirst 会使得结果变大，还有可能
            
            // 当前数与上一个数相同时， 跳过
            if (first > 0 && nums[first] == nums[first - 1])
                continue;

            for (int second = first + 1; second < size - 2; ++second)
            {
                
                // 当前循环最小的可能 后面的不会有更小的情况
                if ((nums[first] + nums[second] + nums[second + 1] + nums[second + 2]) > target)
                    break;
                // 当前循环下最大的可能
                if ((nums[first]  + nums[second] + nums[size - 1] + nums[size - 2]) < target)
                    continue; // 移动第二个数结果会变大， 还有可能
                
                // 当前数与上一个数相同时，跳过
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;

                int thirdleft = second + 1;
                int fourright = size - 1;

                // 寻找第三个 和 第四个数
                while (thirdleft < fourright)
                {
                    int sum = nums[first] + nums[second] + nums[thirdleft] + nums[fourright];
                    // cout << sum << " " << first << second << thirdleft << fourright << endl;
                    // 找到写到结果中去
                    if (sum == target)
                    {
                        result.push_back({nums[first], nums[second], nums[thirdleft], nums[fourright]});
                    }

                    // sum <= target 移动左边的数据
                    if (sum - target <= 0)
                    {
                        thirdleft++;
                        while (thirdleft < fourright && nums[thirdleft - 1] == nums[thirdleft])
                            thirdleft++;
                    }
                    else if (sum - target >= 0)// sum >= target 移动左边的数据
                    {
                        fourright--;
                        while (thirdleft < fourright && nums[fourright + 1] == nums[fourright])
                            fourright--;
                    }
                }
            }
        }

        // return
        return result;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums {1, 0, -1, 0, -2, 2};
    vector<vector<int>> result;
    
    result = s.fourSum(nums, 0);

    cout << "[ 1, 0, -1, 0, -2, 2 ]" << endl << endl;

    for (auto num : result)
    {
        cout << "[";
        for (auto n : num)
            cout << " " << n;
        
        cout << " ]" << endl;
    }

    return 0;
}

// date: 2020-05-01
// desc: 给出一个整数数组，请在数组中找出两个加起来等于目标值的数，
//       你给出的函数twoSum 需要返回这两个数字的下标（index1，index2），需要满足 index1 小于index2.。注意：下标是从1开始的
//       假设给出的数组中只存在唯一解
//       例如：
//       给出的数组为 {2, 7, 11, 15},目标值为9
//       输出 ndex1=1, index2=2

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
    
//         int size = nums.size();
//         for(int i =0; i < size; i++)
//         {
//             for (int j = i + 1; j < size; j++)
//             {
//                 if ((nums[i] + nums[j]) == target) 
//                 {
//                     return {i, j};
//                 }   
//             }    
//         }

//         return {-1, -1};
//     }
// };


        
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    
        int size = nums.size();
        map<int, int> m;
        for(int i =0; i < size; i++)
        {
                if (m.count(nums[i])) 
                {
                    return {m[nums[i]], i};
                }   
                else
                {
                    m[target - nums[i]] = i;
                }
        }

        return {-1, -1};
    }
};


int main(void)
{
    Solution s;
    vector<int> num;
    num.push_back(15);
    num.push_back(2);
    num.push_back(7);
    num.push_back(11);
    int t = 9;

    vector<int> index;

    index = s.twoSum(num, 9); 

    cout << "[15, 2, 7, 11]  9" << endl;
    cout << index[0] << "   " << index[1] << endl;

    return 0;
}

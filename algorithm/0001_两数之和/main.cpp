// date: 2020-03-28
// desc: 

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

    cout << index[0] << "   " << index[1] << endl;

    return 0;
}

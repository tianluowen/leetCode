// date: 2020-04-27
// desc: 在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
//       你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
//       如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
//       说明: 
//         - 如果题目有解，该答案即为唯一答案。
//         - 输入数组均为非空数组，且长度相同。
//         - 输入数组中的元素均为非负数。

#include <iostream>
#include <vector>

using namespace std;
        
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int length = gas.size();
        int currtGas = 0;
        bool flag = true;
        int result = -1;
        
        // 遍历每一个结点
        for (int i = 0; i < length; i++)
        {
            currtGas = 0;
            flag = true;
            // 遍历一圈 不满足 flag = false break;
            for (int currt = i; currt < length; currt++)
            {   
                if (cost[currt] > currtGas + gas[currt])
                {
                    flag = false;
                    break;
                }
                currtGas = currtGas + gas[currt] - cost[currt];
            }
            for (int currt = 0; currt < i; currt++)
            {
                if (cost[currt] > currtGas + gas[currt])
                {
                    flag = false;
                    break;
                } 
                currtGas = currtGas + gas[currt] - cost[currt];
            }
            
            // 获取 索引
            if (flag)
            {
                result = i;
                break;
            }
        }
       
        return result;
    }
};
        
int main(void)
{
    Solution s;

    vector<int> gas {1, 2, 3, 4, 5};
    vector<int> cost {3, 4, 5, 1, 2};

    int result = s.canCompleteCircuit(gas, cost);

    cout << "gas  = [1, 2, 3, 4, 5]" << endl;
    cout << "cost = [3, 4, 5, 1, 2]" << endl;
    cout << "result = " << result << endl;

    return 0;
}

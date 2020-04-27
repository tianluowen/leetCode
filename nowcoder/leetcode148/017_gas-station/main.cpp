// date: 2020-04-27
// desc: 环形路上有n个加油站，第i个加油站的汽油量是gas[i].
// 你有一辆车，车的油箱可以无限装汽油。从加油站i走到下一个加油站（i+1）花费的油量是cost[i]，你从一个加油站出发，刚开始的时候油箱里面没有汽油。
// 求从哪个加油站出发可以在环形路上走一圈。返回加油站的下标，如果没有答案的话返回-1。
// 注意：
// 答案保证唯一

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

// date: 2020-07-04
// desc: 题目描述
//       蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。
//       样例输入
//       5
//       样例输出
//       1 3 6 10 15
//       2 5 9 14
//       4 8 13
//       7 12
//       11

#include <iostream>
 
using namespace std;
 
int main(void)
{
    int n;
    while (cin >> n)
    {
        int temp = 1;
        for (int i = 0; i < n; i++)
        {
             
            int begin = temp + i;
            temp = begin;
            cout << begin << ' ';
            for (int j = 1; j < n - i; j++)
            {
                begin = begin + i + j + 1;
                cout << begin << " ";
            }
            cout << endl;
        }
    }
     
    return 0;
}

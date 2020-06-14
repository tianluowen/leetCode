// date: 2020-06-14
// desc: 给出一个用二维矩阵表示的图像
//       返回该图像顺时针旋转90度的结果
//       扩展：
//       你能使用原地算法解决这个问题么？

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 转置
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // 按 y = n / 2 翻转
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = temp;
            }
        }
    }
};

int main(void)
{
    Solution s;
    vector<vector<int>> matrix {{1, 2, 3}, {4, 5, 6}, {7, 8 ,9}};

    for (int i = 0; i < matrix.size(); i++)
    {
        auto data = matrix[i];

        cout << "[";
        for (int j = 0; j < data.size(); j++)
        {
            if (j != data.size() - 1)
            {
                cout << data[j] << ", "; 
            }
            else
            {
                cout << data[j] << "]"; 
            }
        }

        cout << endl;
    }

    s.rotate(matrix);

    cout << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        auto data = matrix[i];

        cout << "[";
        for (int j = 0; j < data.size(); j++)
        {
            if (j != data.size() - 1)
            {
                cout << data[j] << ", "; 
            }
            else
            {
                cout << data[j] << "]"; 
            }
        }

        cout << endl;
    }

    return 0;
}

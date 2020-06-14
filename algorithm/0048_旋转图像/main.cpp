// date: 2020-06-14
// desc: 给定一个 n × n 的二维矩阵表示一个图像。
//       将图像顺时针旋转 90 度。
//       说明：
//       你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

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

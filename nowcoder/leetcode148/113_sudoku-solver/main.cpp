// date: 2020-05-30
// desc: 请编写一个程序，给数独中的剩余的空格填写上数字
//       空格用字符'.'表示
//       假设给定的数独只有唯一的解法

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // 定义三个 二维数组，分别存储每个数出现
        bool visitRow[9][10] = {false};
        bool visitCol[9][10] = {false};
        bool visitBox[9][10] = {false};

        // 初始化
        for (int col = 0; col < 9; col++)  
        {
            for (int row = 0; row < 9; row++)
            {
                if (board[col][row] != '.')
                {
                    int num = board[col][row] - '0';
                    visitRow[row][num] = true;
                    visitCol[col][num] = true;
                    visitBox[col / 3 * 3 + row / 3][num] = true;
                }
            }
        }
        
        stack<vector<int>> s;   // 每处理一个就存入栈中
        int flag = 0;           // 不为 0 说明是回溯
        for (int row = 0, col = 0; col < 9;)
        {
            if (board[col][row] == '.')
            // 处理每个位置
            {
                int num = flag + 1;
                for (; num < 10; num++)
                {
                    if (visitRow[row][num] || visitCol[col][num] || visitBox[(col / 3) * 3 + row / 3][num])
                    {
                        continue;
                    }
                    else
                    {   
                        // 满足要求
                        s.push({row, col, num});
                        visitRow[row][num] = true;
                        visitCol[col][num] = true;
                        visitBox[col / 3 * 3 + row / 3][num] = true;
                        board[col][row] = num + '0';

                        break;
                    }
                }

                if (num == 10)
                {
                    // 当前位置没有合适的数据，回溯
                    vector<int> temp = s.top();
                    s.pop();
                    row = temp[0];
                    col = temp[1];

                    flag = temp[2];
                    visitRow[row][flag] = false;
                    visitCol[col][flag] = false;
                    visitBox[col / 3 * 3 + row / 3][flag] = false;
                    board[col][row] = '.';
                    
                    continue;
                }
                else
                {
                    // glag = 0 下一个位置从 1 开始遍历
                    flag = 0;
                }
            }

            // change row, col
            ++row;
            if (row == 9)
            {
                ++col;
                row = 0;
            }
        }
    }
};

int main(void)
{
    Solution s;
    vector<vector<char>> board {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'},
    };
    
    for (int i = 0; i < 9; i++)
    {
        cout << "[";
        for (int j = 0; j < 9; j++)
        {
            if (j == 8)
            {
                cout << "\"" << board[i][j] << "\"";
            }
            else
            {
                cout << "\"" << board[i][j] << "\"" << ", ";
            }
        }
        cout << "]" << endl;
    }
    cout << endl;

    s.solveSudoku(board);

    for (int i = 0; i < 9; i++)
    {
        cout << "[";
        for (int j = 0; j < 9; j++)
        {
            if (j == 8)
            {
                cout << "\"" << board[i][j] << "\"";
            }
            else
            {
                cout << "\"" << board[i][j] << "\"" << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}

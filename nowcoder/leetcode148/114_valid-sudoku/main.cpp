// date: 2020-05-23
// desc: 根据数独的规则Sudoku Puzzles - The Rules.判断给出的局面是不是一个符合规则的数独局面
//       数独盘面可以被部分填写，空的位置用字符'.'.表示

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 定义三个 二维数组，分别存储每个数出现
        bool row[9][10] = {false};
        bool column[9][10] = {false};
        bool arra[9][10] = {false};

        // 遍历每个数字
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                // 空的跳过
                if (board[i][j] == '.')
                    continue;
                
                int num = board[i][j] - '0';
                // 行判断
                if (row[i][num] == true)
                    return false;
                else
                    row[i][num] = true;
                
                // 列判断
                if (column[j][num] == true)
                    return false;
                else
                    column[j][num] = true;

                // 3 * 3 判断
                int index = (i / 3) * 3 + j / 3;
                if (arra[index][num] == true)
                    return false;
                else
                    arra[index][num] = true;
            }
        }

        return true;
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
    
    bool result = s.isValidSudoku(board);

    cout << "[\"5\",\"3\",\".\",\".\",\"7\",\".\",\".\",\".\",\".\"],\n[\"6\",\".\",\".\",\"1\",\"9\",\"5\",\".\",\".\",\".\"],\n[\".\",\"9\",\"8\",\".\",\".\",\".\",\".\",\"6\",\".\"],\n[\"8\",\".\",\".\",\".\",\"6\",\".\",\".\",\".\",\"3\"],\n[\"4\",\".\",\".\",\"8\",\".\",\"3\",\".\",\".\",\"1\"],\n[\"7\",\".\",\".\",\".\",\"2\",\".\",\".\",\".\",\"6\"],\n[\".\",\"6\",\".\",\".\",\".\",\".\",\"2\",\"8\",\".\"],\n[\".\",\".\",\".\",\"4\",\"1\",\"9\",\".\",\".\",\"5\"],\n[\".\",\".\",\".\",\".\",\"8\",\".\",\".\",\"7\",\"9\"]" << endl;

    cout << endl << "result = " << boolalpha << result << endl;

    return 0;
}

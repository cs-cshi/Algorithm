/**
 * 37. 解数独
 * 编写一个程序，通过填充空格来解决数独问题。
 * 数独的解法需遵循如下规则：
 *     - 数字 1-9 在每一行只能出现一次。
 *     - 数字 1-9 在每一列只能出现一次。
 *     - 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 * 数独部分空格内已填入了数字，空白格用 '.' 表示。
 * 链接：https://leetcode-cn.com/problems/sudoku-solver
 */

#include <vector>
#include <iostream>

using std::cout;
using std::endl;
// using std::fill;
using std::vector;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        backtracking(board);
    }

    bool backtracking(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')     // 当前位置已放置
                    continue;
                for (char k = '1'; k <= '9'; k++)
                {
                    if (isValid(i, j, k, board))    // 当前元素放置 k
                    {
                        board[i][j] = k;
                        if(backtracking(board))     // 当前元素放置 k 后继续递归放置下一个元素，如果都成功返回 true，说明是正确路径
                            return true;
                        board[i][j] = '.';          // 否则当前元素不能是 k，k 继续遍历
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool isValid(int row, int col, char val, vector<vector<char>> &board)
    {
        // int used[9] = {0};
        // 检查行
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == '.' || i == col)
                continue;
            if (board[row][i] == val)
                return false;
            // used[board[row][i] - '1']++;
            // if (used[board[row][i] - '1'] > 1)
            //     return false;
        }

        // 检查列
        // fill(used,used+9,0);
        // used[9] = {0};
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == '.' || row == i)
                continue;
            if (board[i][col] == val)
                return false;
            // used[board[i][col] - '1']++;
            // if (used[board[i][col] - '1'] > 1)
            //     return false;
        }

        // 检查子宫格内
        // fill(used,used+9,0);
        int startX = 3 * (row / 3);
        int startY = 3 * (col / 3);
        for (int i = startX; i < startX + 3; i++)
        {
            for (int j = startY; j < startY + 3; j++)
            {
                if (board[i][j] == '.' || (i == row && j == col))
                    continue;
                if(board[i][j]==val)
                    return false;
                // used[board[i][j] - '1']++;
                // if (used[board[i][j] - '1'] > 1)
                //     return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> board = {
        {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
        {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
        {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
        {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
        {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
        {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
    bool result = solution.isValid(5, 5, '4', board);
    cout << result << endl;
}
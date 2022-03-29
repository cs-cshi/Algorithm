/**
 * 51. N 皇后
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 链接：https://leetcode-cn.com/problems/n-queens
 */

#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<string> chessboard(n, string(n, '.'));
        if (n > 0)
            backstracking(result, chessboard, 0, n);
        return result;
    }

    void backstracking(vector<vector<string>> &result, vector<string> &chessboard, int row, int n)
    {
        if (row == n)
        {
            result.push_back(chessboard);
            return;
        }

        // 横向遍历，相当于在某行每一列都尝试放至红皇后
        for (int col = 0; col < n; col++)
        {
            if (!isValid(row, col, chessboard, n))  // 当前位置冲突
                continue;
            chessboard[row][col] = 'Q';
            backstracking(result, chessboard, row + 1, n);  // 在下一行中寻找合适的位置
            chessboard[row][col] = '.';
        }
    }

    // 判断当前位置放皇后是否有效
    bool isValid(int row, int col, vector<string> &chessboard, int n)
    {
        // 检查列
        for (int i = 0; i < row; i++)
            if (chessboard[i][col] == 'Q')
                return false;

        // 检查 45° 角
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (chessboard[i][j] == 'Q')
                return false;

        // 检查 115° 角
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (chessboard[i][j] == 'Q')
                return false;

        return true;
    }
};

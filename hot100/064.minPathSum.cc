/*
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
*/

#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::min;
using std::vector;

// 使用动规，dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + dp[i][j];
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(grid);  // 求最小路径和，带权重，需要用来原来的数组

    dp[0][0] = grid[0][0];

    // 处理上边界
    for (int i = 1; i < m; ++i)
        dp[i][0] += dp[i - 1][0];

    // 处理左边界
    for (int j = 1; j < n; ++j)
        dp[0][j] += dp[0][j - 1];

    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);

    return dp[m - 1][n - 1];
}

int main()
{
    vector<vector<int>> ans({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}});
    minPathSum(ans);
}
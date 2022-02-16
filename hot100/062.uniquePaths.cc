/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// dfs 超时
void backtrack(int m, int n, int x, int y, int &ans)
{
    if (x == m && y == n)
    {
        ans++;
        return;
    }

    if (x > m || y > n)
        return;

    backtrack(m, n, x + 1, y, ans);
    backtrack(m, n, x, y + 1, ans);
}

int uniquePaths(int m, int n)
{
    int ans = 0;
    backtrack(m, n, 1, 1, ans);
    return ans;
}

// dp
// f[i][j] = f[i-1]f[j-1]，f[i][j] 表示从 0,0 到 i,j 路径数量
int uniquePaths2(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0; i < m; ++i)
        dp[i][0] = 1;

    for (int j = 0; j < n; ++j)
        dp[0][j] = 1;

    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    // for (int i = 0; i < m; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //         cout << dp[i][j] << '\t';
    //     cout << endl;
    // }
    return dp[m - 1][n - 1];
}

// 数学组合方法，共移动 m+n-2次，其中 m-1次向下，n-1 向右
// 因此路径数目等价于：m+n-2 次中，选择 m-1 次向下的组合数
int uniquePaths3(int m, int n)
{
    long long ans = 1;

    for (int x = n, y = 1; y < m; ++x, ++y)
        ans = ans * x / y;

    return ans;
}

int main()
{
    int ret = uniquePaths3(19, 13);
    cout << ret << endl;
    return 0;
}
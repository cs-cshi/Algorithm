/**
 * 62. 不同路径
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 * 问总共有多少条不同的路径？
 * 链接：https://leetcode-cn.com/problems/unique-paths
 */

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // dp[i][j]   索引 i、j  处路径条数
        // 递归公式    dp[i][j] = dp[i-1][j] + dp[i][j-1]
        // 初始化dp    dp[0][j] = 1, dp[i][0] = 1
        // 遍历顺序
        // 举例论证
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    int m = 3;
    int n = 7;
    Solution solution;
    int result = solution.uniquePaths(3, 7);
    
}
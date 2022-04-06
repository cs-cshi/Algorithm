/**
 * 63. 不同路径 II
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 * 链接：https://leetcode-cn.com/problems/unique-paths-ii
 */

#include <vector>

using std::vector;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 1));
        for (int i = 0; i < obstacleGrid.size(); i++)
        {
            for (int j = 0; j < obstacleGrid[0].size(); j++)
            {
                if (obstacleGrid[i][j] == 1) // 障碍物的位置
                {
                    dp[i][j] = 0;
                    continue;
                }

                if (i == 0 && j == 0)
                    continue;

                if (i == 0)
                { // 边界初始化
                    dp[i][j] = dp[i][j - 1];
                    continue;
                }

                if (j == 0)
                { // 边界初始化
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }

                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
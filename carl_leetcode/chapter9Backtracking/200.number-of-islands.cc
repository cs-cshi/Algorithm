/**
 * 200. 岛屿数量
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 此外，你可以假设该网格的四条边均被水包围。
 * 链接：https://leetcode.cn/problems/number-of-islands
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 0)
            return 0;

        int m = grid.size();
        int n = grid[0].size();
        // 也可以不用 vis,直接将访问过的 grid 由 1 改为 0
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    ans++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int x, int y)
    {
        vis[x][y] = true;
        int m = grid.size();
        int n = grid[0].size();
        // for(int i = 0; i < 4; i++) {
        //     int newX = dis[i].first + x;
        //     int newY = dis[i].second + y;
        //     if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == '1' && !vis[newX][newY])
        //         dfs(grid, vis, newX, newY);
        // }
        for (const auto &[i, j] : dis)
        {
            int newX = i + x;
            int newY = j + y;
            if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == '1' && !vis[newX][newY])
                dfs(grid, vis, newX, newY);
        }
    }

private:
    static vector<pair<int, int>> dis;
};

vector<pair<int, int>> Solution::dis = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
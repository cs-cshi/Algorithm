/**
 *
 */
#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

void dfs(const vector<string> &matrix, const vector<int> &start, vector<vector<int>> &ans, int count, queue<vector<int>> &que);

void expand(const vector<string> &matrix, const vector<int> &start, vector<vector<int>> &ans, int count, queue<vector<int>> &que);

int conveyorBelt(vector<string> &matrix, vector<int> &start, vector<int> &end)
{
    /**
     * 不是动规，此思路无效
     * dp[i][j]: 传送到 [i,j] 处最小需要移动的次数
     * dp[i][j] = min(dp[i-1][j] + up,dp[i+1][j] + down, dp[i][j-1]+left,dp[i][j+1]+right);
     * dp[0][0] = 0
     * 遍历顺序：左右上下
     */

    vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), INT32_MAX));

    // 初始化
    queue<vector<int>> que;
    int count = 0;
    dfs(matrix, start, ans, count, que);

    while (!que.empty())
    {
        int size = que.size();
        count++;
        while (size--)
        {
            vector<int> pos = que.front();
            que.pop();
            expand(matrix, pos, ans, count, que);
        }
    }
    // 实际上可以不计算出抵达所有结点需要改变的次数，当 dfs 抵达 end 结点时就可以退出
    return ans[end[0]][end[1]]; 
}

//  当前结点变化一次后上下左右四个方向可能访问的结点
void expand(const vector<string> &matrix, const vector<int> &start, vector<vector<int>> &ans, int count, queue<vector<int>> &que)
{
    int i = start[0];
    int j = start[1];

    // 上
    if (matrix[i][j] != '^' && i > 0)
    {
        dfs(matrix, {i - 1, j}, ans, count, que);
    }

    // 下
    if (matrix[i][j] != 'v' && i < matrix.size() - 1)
        dfs(matrix, {i + 1, j}, ans, count, que);

    // 左
    if (matrix[i][j] != '<' && j > 0)
        dfs(matrix, {i, j - 1}, ans, count, que);

    // 右
    if (matrix[i][j] != '>' && j < matrix[0].size() - 1)
        dfs(matrix, {i, j + 1}, ans, count, que);
}

// ^v<>
// 以 start[0][1] 为起点，沿着箭头方向做一次 dfs
void dfs(const vector<string> &matrix, const vector<int> &start, vector<vector<int>> &ans, int count, queue<vector<int>> &que)
{
    int i = start[0];
    int j = start[1];

    while (true)
    {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
            return;

        if (ans[i][j] != INT32_MAX)
            return;

        que.push({i, j});
        ans[i][j] = count;

        if (matrix[i][j] == '^') // 上
            i--;
        else if (matrix[i][j] == 'v') // 下
            i++;
        else if (matrix[i][j] == '<') // 左
            j--;
        else // 右
            j++;
    }
}

int main()
{
    vector<string> matrix = {">>v", "v^<", "<><"};
    vector<int> start = {0,1};
    vector<int> end = {2,0};
    int result = conveyorBelt(matrix, start, end);
    cout << result << endl;
}
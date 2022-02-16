/*
    给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::stack;
using std::vector;

// 先计算出每个点左边连续1的个数，然后采用 084.柱状图中最大矩形 的解法求最大矩形,枚举每一条底
int maximalRectangle(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    if (m == 0)
        return 0;
    int n = matrix[0].size();

    vector<vector<int>> left(m, vector<int>(n, 0)); // 存储底

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '1')
                left[i][j] = j == 0 ? 1 : left[i][j - 1] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '0')
                continue;

            int width = left[i][j];
            for (int k = i; k >= 0; k--)
            {
                width = min(width, left[k][j]);
                ans = max(ans, (i - k + 1) * width);
            }
        }
    }
    return ans;
}

// 和上种解法一样思路，枚举高，使用单调栈，对每一列用单调栈求出左右边界
int maximalRectangle2(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    if (m == 0)
        return 0;
    int n = matrix[0].size();

    vector<vector<int>> left(m, vector<int>(n, 0)); // 存储底

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '1')
                left[i][j] = j == 0 ? 1 : left[i][j - 1] + 1;
        }
    }

    int ans = 0;
    // 将每一列当做底，连续1的数目当柱子高度，求当前底下最大面积，记录最值
    for (int j = 0; j < n; j++)
    {
        stack<int> mono_stack;
        vector<int> up(m, 0);
        // 确定每个点上界
        for (int i = 0; i < m; i++)
        {
            while (!mono_stack.empty() && left[mono_stack.top()][j] >= left[i][j])
                mono_stack.pop();
            up[i] = mono_stack.empty() ? -1 : mono_stack.top();
            mono_stack.push(i);
        }
        // 确定每个点下界
        mono_stack = stack<int>();
        vector<int> down(m, m);
        for (int i = m - 1; i >= 0; i--)
        {
            while (!mono_stack.empty() && left[mono_stack.top()][j] >= left[i][j])
                mono_stack.pop();
            down[i] = mono_stack.empty() ? m : mono_stack.top();
            mono_stack.push(i);
        }

        // 根据上下界求出最值
        for (int i = 0; i < m; i++)
            ans = max(ans, (down[i] - up[i] - 1) * left[i][j]);
    }
    return ans;
}

// 使用单调栈，一次遍历确定左右界
int maximalRectangle3(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    if (m == 0)
        return 0;
    int n = matrix[0].size();

    vector<vector<int>> left(m, vector<int>(n));
    // 柱状图初始化
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '1')
                left[i][j] = j == 0 ? 1 : left[i][j - 1] + 1;
        }
    }

    int ans = 0; // 存储最大面积
    // 将每一列当作底，用单调栈求当前列的最值
    for (int j = 0; j < n; j++)
    {
        stack<int> mono_stack;
        vector<int> up(m, -1);
        vector<int> down(m, m);

        for (int i = 0; i < m; i++)
        {
            while (!mono_stack.empty() && left[mono_stack.top()][j] >= left[i][j])
            {
                down[mono_stack.top()] = i;
                mono_stack.pop();
            }
            up[i] = mono_stack.empty() ? -1 : mono_stack.top();
            mono_stack.push(i);
        }

        // 更新当前最值
        for (int i = 0; i < m; i++)
            ans = max(ans, (down[i] - up[i] - 1) * left[i][j]);
    }
    return ans;
}

int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    int ret = maximalRectangle3(matrix);
    cout << ret << endl;
    return 0;
}
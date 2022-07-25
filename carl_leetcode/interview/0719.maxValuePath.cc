#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int dirs[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
static int vals[3] = {1, 3, 5};

int dfs(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &memo)
{
    if (memo[row][col] != 0)
    {
        return memo[row][col];
    }
    memo[row][col] = memo[row][col] + vals[matrix[row][col] - 1];
    for (int i = 0; i < 8; ++i)
    {
        int newRow = row + dirs[i][0], newCol = col + dirs[i][1];
        if (newRow >= 0 && newRow < 4 && newCol >= 0 && newCol < 4 && matrix[newRow][newCol] == matrix[row][col])
        {
                memo[row][col] = max(memo[row][col], dfs(matrix, newRow, newCol, memo) + vals[matrix[row][col] - 1]);
        }
    }
    return memo[row][col];
}

int maxValuePath(vector<vector<int>> &matrix)
{
    int ans = 0;
    if (matrix.size() == 0 || matrix[0].size() == 0)
        return 0;

    auto memo = vector<vector<int>>(4, vector<int>(4, 0));
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            ans = max(ans, dfs(matrix, i, j, memo));
        }
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++)
            cout << memo[i][j] << "  ";
        cout <<endl;
    }

    return ans;
}

int main()
{
    vector<vector<int>> test = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
    int ans = maxValuePath(test);
    cout << ans << endl;

    return 0;
}
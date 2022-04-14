/**
 * 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 */
#include <vector>

using std::vector;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> res(n, vector<int>(n, 0));
    int startX = 0; // 每一圈起始坐标
    int startY = 0;
    int offset = 1;   // 每一圈长度
    int loop = n / 2; // 总圈数
    int i, j;
    int mid = n / 2; // 奇数时最中间单独赋值
    int count = 1;   // 赋值

    //  转圈
    while (loop--)
    {
        i = startX;
        j = startY;

        // 模拟转一圈
        // 上侧从左至右
        for (; j < n + startY - offset; j++)
            res[i][j] = count++;

        // 右侧从上至下
        for (; i < n + startX - offset; i++)
            res[i][j] = count++;

        // 下侧从右至左
        for (; j > startY; j--)
            res[i][j] = count++;

        // 左侧从下至上
        for (; i > startX; i--)
            res[i][j] = count++;

        // 下一轮起始坐标
        startX++;
        startY++;

        // 下一轮一圈每条边长度
        offset += 2;
    }

    // n 为奇数，最中心单独赋值
    if (n % 2 == 1)
        res[mid][mid] = count;

    return res;
}

vector<vector<int>> generateMatrix2(int n)
{
    vector<vector<int>> result(n, vector<int>(n, 0));
    int loop = n / 2;
    int startX = 0;
    int startY = 0;
    int offset = 1; //每一圈的长度
    int mid = n / 2;
    int count = 1;
    int i, j;
    while (loop--)
    {
        i = startX;
        j = startY;

        // 上界左->右
        for (; j < startY + n - offset; j++)
            result[i][j] = count++;

        // 右界上->下
        for (; i < startX + n - offset; i++)
            result[i][j] = count++;

        // 下界右->左
        for (; j > startY; j--)
            result[i][j] = count++;

        // 左界下->上
        for (; i > startX; i--)
            result[i][j] = count++;

        startX++;
        startY++;
        offset += 2;
    }

    if (n % 2 == 1)
        result[mid][mid] = count;

    return result;
}

vector<vector<int>> generateMatrix3(int n)
{
    int offset = 1;
    int startX = 0, startY = 0;
    int loop = n / 2;
    int count = 1;
    vector<vector<int>> res(n, vector<int>(n));

    while (loop--)
    {
        int i = startX;
        int j = startY;

        // 上界从左至右
        for (; j < n + startY - offset; j++)
            res[i][j] = count++;

        // 右界从上至下
        for (; i < n + startX - offset; i++)
            res[i][j] = count++;

        // 下届从右至左
        for (; j > startY; j--)
            res[i][j] = count++;

        // 左界从下至上
        for (; i > startX; i--)
            res[i][j] = count++;

        startX++;
        startY++;
        offset += 2;
    }
    if (n % 2 == 1)
        res[n / 2][n / 2] = count;

    return res;
}

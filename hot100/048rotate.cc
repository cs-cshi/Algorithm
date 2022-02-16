/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
*/

#include <vector>
#include <iostream>

using std::vector;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // 遍历的每一个数，会将旋转 360° 时每个位置的值都进行旋转，因此只需要遍历当前 matrix 左上角的 matrix 即可
    for (int row = 0; row < n / 2 + 1; row++)
    {
        for (int col = 0; col < n / 2; col++)
        {
            /*
            旋转 90°，原本第 row 行第 col 列，会转为第 col 行，倒数第 row 列
            */
            int temp = matrix[row][col];
            matrix[row][col] = matrix[n - col - 1][row];
            matrix[n - col - 1][row] = matrix[n - row - 1][n - col - 1];
            matrix[n - row - 1][n - col - 1] = matrix[col][n - row - 1];
            matrix[col][n - row - 1] = temp;
        }
    }
}

int main()
{
    return 0;
}
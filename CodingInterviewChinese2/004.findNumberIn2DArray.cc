/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include <iostream>
#include <vector>

using namespace std;

// 线性时间，O(M+N)，利用类似于二叉树的性质
bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
{
    if (matrix.size() <= 0)
        return false;
    
    int row = 0;    // 索引
    int column = matrix[0].size() - 1;      // 索引

    while (row < matrix.size() && column >= 0)
    {
        if( target > matrix[row][column])
            row++;
        else if (target < matrix[row][column])
            column--;
        else
            return true;
    }
    return false;
}

int main()
{
    // C++ 二维数组测试
    vector<vector<int>> data{{1, 2, 3, 4, 5}, {6, 7, 8, 9}};
    for (auto rows : data)
    {
        for (auto num : rows)
            cout << num << "  ";
        cout << endl;
    }
    int row = data.size();
    cout << row << endl;
    int column = data[0].size();
    cout << column << endl;
    return 0;
}
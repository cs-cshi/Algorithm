/* 
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
*/
#include <vector>
#include <string>

using std::pair;
using std::string;
using std::vector;

bool backtrack(vector<vector<char>> &board, vector<vector<int>> &visited, int row, int col, string &word, int idx)
{
    if (board[row][col] != word[idx])
        return false;
    else if (idx == word.size() - 1)
        return true;

    visited[row][col] = true;
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 四个方向
    bool result = false;
    // 依次对四个方向回溯
    for (const auto &dir : directions)
    {
        int newRow = row + dir.first;
        int newCol = col + dir.second;
        // 保证四个方向不越界
        if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size())
        {
            if (!visited[newRow][newCol])
            {
                bool flag = backtrack(board, visited, row, col, word, idx + 1);
                if(flag){
                    result = true;
                    break;
                }
            }
        }
    }
    visited[row][col] = false;
    return result;
}

bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> visited(m,vector<int>(n));  // 用于存储当前结点是否已经判断过
    // 遍历每一个结点，对每个结点判断是否能找到
    for(int i = 0; i<m;i++){
        for(int j = 0;j<n;j++){
            bool flag = backtrack(board,visited,i,j,word,0);
            if (flag)
                return true;
        }
    }
    return false;
}

int main() {}
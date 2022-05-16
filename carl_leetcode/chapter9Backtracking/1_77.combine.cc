/**
 * 77. 组合
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 * 你可以按 任何顺序 返回答案。
 */

#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> path;
        backtracking(result, path, n, k, 1);
        return result;
    }

    /**
     * 回溯三要素：
     * 1. 确定返回值和参数
     * 2. 确定终止条件
     * 3. 确定单层搜索过程
     */
    void backtracking(vector<vector<int>> &result, vector<int> &path, int n, int k, int startIndex)
    {
        if (path.size() == k)
        {
            result.emplace_back(path);
            return;
        }

        // for (int i = startIndex; i <= n; i++)   // 横向，单层搜索
        // k - path.size <= n - i + 1
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) // 剪枝，用 path = 0 是来确定+1，至多从哪里开始遍历
        {
            // 处理节点
            path.push_back(i);
            backtracking(result, path, n, k, i + 1); // 纵向
            path.pop_back();
        }
    }
};
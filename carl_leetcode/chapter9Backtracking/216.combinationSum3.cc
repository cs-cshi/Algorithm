/**
 * 216. 组合总和 III
 * 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
 *   - 只使用数字1到9
 *   - 每个数字 最多使用一次 
 * 返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
 * 链接：https://leetcode-cn.com/problems/combination-sum-iii
 */

#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> result;
        vector<int> path;
        int sum = 0;
        backtracking(result, path, 1, sum, k, n);
    }

    void backtracking(vector<vector<int>> &result, vector<int> &path, int startIndex, int sum, int k, int n)
    {
        // if (sum > n)
        //     return;

        if (path.size() == k)
        {
            if (sum == n)
                result.push_back(path);
            return;
        }

        for (int i = startIndex; i <= 9; i++) // 横向
        {
            if (sum > n) // 剪枝，当前 sum 和已经大于 targetSum 了，不需要向后回溯（给定元素递增）
                break;   // 当前都不需要再横向了，有序
            path.push_back(i);
            sum += i;
            backtracking(result, path, i + 1, sum, k, n); // 注意 i+1，纵向
            sum -= i;
            path.pop_back();
        }
    }
};

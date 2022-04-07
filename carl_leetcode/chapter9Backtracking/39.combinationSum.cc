/**
 * 39. 组合总和
 * 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
 * candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
 * 对于给定的输入，保证和为 target 的不同组合数少于 150 个。
 * 链接：https://leetcode-cn.com/problems/combination-sum
 */

#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> path;
        backtracking(result, path, 0, 0, candidates, target);
        return result;
    }

    // 需要设置 indexStart，如果不设置，每次从 0 开始，那么所有结果会有两份
    void backtracking(vector<vector<int>> &result, vector<int> &path, int sum, int indexStart, vector<int> &candidates, int target)
    {

        if (sum == target)
        {
            if (sum == target)
                result.push_back(path);
            return;
        }
        // for (int i = indexStart; i < candidates.size() && sum + candidates[i] <= target; i++)
        for (int i = indexStart; i < candidates.size(); i++)
        {
            if (sum + candidates[i] > target) //  剪枝，不可以加在 for 循环体中，for 循环体会直接不再横向
                continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(result, path, sum, i, candidates, target); // 不需要 i+1，表示当前数值可以重复选取
            sum -= candidates[i];
            path.pop_back();
        }
    }
};
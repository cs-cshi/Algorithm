/**
 * 40. 组合总和 II
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 * 注意：解集不能包含重复的组合。 
 * 链接：https://leetcode-cn.com/problems/combination-sum-ii
 */

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using std::sort;
using std::vector;
// using std::unordered_set;
// using std::multiset;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(result, path, 0, 0, used, candidates, target);
        return result;
    }

    void backtracking(vector<vector<int>> &result, vector<int> &path, int indexStart, int sum, vector<bool> &used, vector<int> &candidates, int target)
    {
        if (sum == target)
        {
            result.emplace_back(path);
            return;
        }

        for (int i = indexStart; i < candidates.size() && sum + candidates[i] <= target; i++)
        {   
            // used[i-1] = true 是纵向， used[i-1] = false 是横向
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) // 深度优先，当深度又返回到同层时， used 状态会回归为层次时的状态
                continue;
            // if(set.find(candidates[i]) == set.end())    // 找到了重复的
            // continue;    // 用set无法区分是横向重复还是纵向重复
            // multiSet.
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(result, path, i + 1, sum, used, candidates, target);
            sum -= candidates[i];
            used[i] = false;
            path.pop_back();
        }
    }
    // private:
    // unordered_set<int> set;
    // multiset<int> multiSet;
};
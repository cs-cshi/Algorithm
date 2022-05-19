/**
 * 491. 递增子序列
 * 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
 * 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
 * 链接：https://leetcode-cn.com/problems/increasing-subsequences
 */

#include <vector>
#include <unordered_set>

using std::unordered_set;
using std::vector;

class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        if (nums.size() > 1)
            backtracking(result, path, 0, nums);
        return result;
    }

    void backtracking(vector<vector<int>> &result, vector<int> &path, int startIndex, vector<int> &nums)
    {
        if (path.size() >= 2)
            result.emplace_back(path);

        unordered_set<int> uset; // 用于同层去重
        for (int i = startIndex; i < nums.size(); i++)
        {
            if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end())
                continue;
            uset.insert(nums[i]);
            path.emplace_back(nums[i]);
            backtracking(result, path, i + 1, nums);
            path.pop_back();
            uset.erase(nums[i]);
        }
    }

    void backtracking2(vector<vector<int>> &result, vector<int> &path, int startIndex, vector<int> &nums)
    {
        if (path.size() >= 2)
            result.emplace_back(path);

        // unordered_set<int> uset; // 用于同层去重
        int used[201] = {0};
        for (int i = startIndex; i < nums.size(); i++)
        {
            if ((!path.empty() && nums[i] < path.back()) || used[nums[i] + 100] != 0)
                continue;
            // uset.insert(nums[i]);
            used[nums[i] + 100]++;
            path.emplace_back(nums[i]);
            backtracking(result, path, i + 1, nums);
            path.pop_back();
        }
    }
};

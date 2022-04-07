/**
 * 90. 子集 II
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 * 链接：https://leetcode-cn.com/problems/subsets-ii
 */

#include <vector>
#include <algorithm>

using std::sort;
using std::vector;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(),nums.end());
        if (nums.size() > 0)
            backtracking(result, path, 0, used, nums);
        return result;
    }

    void backtracking(vector<vector<int>> &result, vector<int> &path, int startIndex, vector<bool> &used, vector<int> &nums)
    {
        result.emplace_back(path);

        for (int i = startIndex; i < nums.size(); i++)
        {
            if (i > 1 && used[i - 1] == false && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(result, path, i+1, used, nums);
            path.pop_back();
            used[i] = false;
        }
    }
};
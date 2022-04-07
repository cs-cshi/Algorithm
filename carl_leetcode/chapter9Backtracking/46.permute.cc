/**
 * 46. 全排列
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 链接：https://leetcode-cn.com/problems/permutations/
 */

#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(),false);
        if(nums.size()>0)
            backtracking(result,path,used,nums);
        return result;
    }

    void backtracking(vector<vector<int>> &result, vector<int> &path, vector<bool> used, vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == true)
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(result, path, used, nums);
            path.pop_back();
            used[i] = false;
        }
    }
};
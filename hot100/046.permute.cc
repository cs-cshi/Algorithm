/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
*/

#include <vector>
#include <algorithm>

using std::swap;
using std::vector;

// 回溯，dfs
void backtrack(vector<vector<int>> &result, vector<int> &nums, int idx, int len)
{
    if (idx == len)
    {
        result.emplace_back(nums);
        return;
    }

    for (int i = idx; i < len; i++)
    {
        // 依次交换 idx 与后续的每个位置
        swap(nums[idx], nums[i]);
        backtrack(result, nums, idx + 1, len); // dfs
        // 撤销交换
        swap(nums[idx], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    backtrack(result, nums, 0, nums.size());
    return result;
}

int main()
{
    return 0;
}
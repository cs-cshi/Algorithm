/**
 * 78. 子集
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集
 */

#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        if (nums.size() > 0)
            backtracking(result, path, 0, nums);
        return result;
    }

    void backtracking(vector<vector<int>> &result, vector<int> &path, int startIndex, vector<int> &nums)
    {
        result.emplace_back(path);     // 所有可能子集，任意个数
        if (startIndex == nums.size()) // 可以不加终止条件，i+1表示最后时不会进入 for 循环体，不会继续往下了
            return;

        for (int i = startIndex; i < nums.size(); i++)
        {
            path.emplace_back(nums[i]);
            backtracking(result, path, i + 1, nums);
            path.pop_back();
        }
    }
};
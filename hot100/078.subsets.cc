/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
*/
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void backtrack(vector<int> &nums, int idx, vector<int> &current, vector<vector<int>> &ans)
{
    // 退出条件
    if (idx == nums.size())
    {
        ans.push_back(current);
        return;
    }
    // 考虑当前位置
    current.emplace_back(nums[idx]);
    backtrack(nums, idx + 1, current, ans);
    // 不考虑当前位置
    current.pop_back();
    backtrack(nums, idx + 1, current, ans);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> current;
    backtrack(nums, 0, current, ans);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    for (auto items : ans)
    {
        cout << '[';
        for (auto item : items)
            cout << item << ' ';
        cout << ']';
    }
}
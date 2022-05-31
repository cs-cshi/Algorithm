/**
 * 47. 全排列 II
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 * 链接：https://leetcode-cn.com/problems/permutations-ii/
 */

#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        if(nums.size()>0)
            backtracking(result,path,used,nums);
        return result;
    }

    void backtracking(vector<vector<int>> &result, vector<int> &path, vector<bool> &used, vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // used[i]==true 当前位置已经使用，纵向，i 是从 0开始
            // nums[i - 1] == nums[i] && used[i - 1] == false  同层重复
            // nums[i - 1] == nums[i] && used[i - 1] == true  树枝重复
            if ((i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false))       // 横向去重（每次从0开始） + 纵向去重
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(result,path,used,nums);
            used[i] = false;
            path.pop_back();
        }
    }
};
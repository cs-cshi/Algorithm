/**
 * 377. 组合总和 Ⅳ
 * 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
 * 题目数据保证答案符合 32 位整数范围。
 * 链接：https://leetcode-cn.com/problems/combination-sum-iv
 */

#include <vector>

using std::vector;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        // 完全背包
        // dp[j] 凑成和为 j 的组合个数
        // dp[j] += dp[j-nums[i]]
        // dp[0] = 1

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        // for (int i = 0; i < nums.size(); i++)
        //     for (int j = nums[i]; j <= target; j++)
        //         dp[j] += dp[j - nums[i]];

        for (int i = 0; i <= target; i++)
            for (int j = 0; j < nums.size(); j++)
                if (i >= nums[j] && dp[i] < __INT_MAX__ - dp[i - nums[j]])
                    dp[i] += dp[i - nums[j]];
        return dp[target];
    }
};
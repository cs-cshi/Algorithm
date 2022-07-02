/**
 * 213. 打家劫舍 II
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
 * 链接：https://leetcode.cn/problems/house-robber-ii
 */

#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];

        int result1 = myRob(nums, 0, nums.size() - 2); // 去掉尾巴
        int result2 = myRob(nums, 1, nums.size() - 1); // 去掉首部
        return max(result1, result2);
    }

    int myRob(vector<int> &nums, int start, int end)
    {
        if (end == start)
            return nums[end];
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        // dp[start + 1] = nums[start + 1];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }

    /**
     * 问题：递归过程中，首的元素值对中间的计算会产生影响，即使最后区分，但还是会出错
     */
    int rob3(vector<int> &nums)
    {
        // dp[i][j] : dp[i][0]：第 i 号房能偷到的最高金额， dp[i][1]表示包括第 1 号房
        // dp[i][0] = max(dp[i-2][0], dp[i-3][0]) + nums[i]
        // dp[0][0] = nums[0], dp[1][0] = nums[1], dp[2][0] = dp[0][0] + nums[2]
        // 正序

        int len = nums.size();
        if (len == 1)
            return nums[0];
        else if (len == 2)
            return max(nums[0], nums[1]);

        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0] = nums[0];
        dp[0][1] = 1;
        dp[1][0] = nums[1];
        dp[2][0] = dp[0][0] + nums[2];
        dp[2][1] = 1;

        for (int i = 3; i < len; i++)
        {
            int preIndex = 0;
            if (dp[i - 2][0] == dp[i - 3][0])
            {
                if (dp[i - 2][1] == 0)
                    preIndex = i - 2;
                else
                    preIndex = i - 3;
            }
            else
                preIndex = dp[i - 2][0] > dp[i - 3][0] ? i - 2 : i - 3;
            dp[i][0] = dp[preIndex][0] + nums[i];
            dp[i][1] = dp[preIndex][1];
        }

        // cout << dp[len-1][1] << endl;
        if (dp[len - 1][1] == 1)
            return max(nums[len - 1], max(dp[len - 2][0], dp[len - 3][0]));
        // cout << 11 << endl;
        return max(dp[len - 1][0], dp[len - 2][0]);
    }
};
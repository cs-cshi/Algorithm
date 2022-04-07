/**
 * 322. 零钱兑换
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 * 你可以认为每种硬币的数量是无限的。
 * 链接：https://leetcode-cn.com/problems/coin-change
 */

#include <vector>
#include <algorithm>

using std::min;
using std::vector;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // dp[j] 凑足总金额 j 最少需要的硬币个数
        // dp[j] = min(dp[j],dp[j-nums[i]+1)
        vector<int> dp(amount + 1, __INT_MAX__);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
        return dp[amount];
    }
};
/**
 * 746. 使用最小花费爬楼梯
 * 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
 * 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
 * 请你计算并返回达到楼梯顶部的最低花费。
 * 链接：https://leetcode-cn.com/problems/min-cost-climbing-stairs
 */

#include <vector>
#include <algorithm>

using std::min;
using std::vector;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        return minCostClimbingStairs2(cost);
    }
    int minCostClimbingStairs2(vector<int> &cost)
    {
        // dp[i] 上升到第 i 个台阶需要支付的费用总的费用
        // dp[i] = min(dp[i - 1] + cost[i-1], dp[i - 2] + cost[i-2])
        // 初始花 dp  dp[0] = 0  dp[1] = 0
        // 确定递归顺序
        // 举例推导公式

        if (cost.size() < 2)
            return 0;

        vector<int> dp(cost.size());
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i < cost.size(); i++)
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);

        return min(dp[cost.size() - 1] + cost[cost.size() - 1], dp[cost.size() - 2] + cost[cost.size() - 2]);
    }

    int minCostClimbingStairs3(vector<int> &cost)
    {
        // dp[i] 从第 i 个台阶爬到上一个台阶需要支付的费用总和
        // dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]
        // 初始花 dp  dp[0] = cost[0]  dp[1] = cost[1]
        // 确定递归顺序
        // 举例推导公式
        if (cost.size() < 2)
            return 0;

        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++)
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];

        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }

    int minCostClimbingStairs4(vector<int> &cost)
    {
        if (cost.size() < 2)
            return 0;

        vector<int> dp(3);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++)
        {
            dp[2] = min(dp[0],dp[1]) + cost[i];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }
};
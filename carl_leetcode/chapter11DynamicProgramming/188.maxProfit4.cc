/**
 * 188. 买卖股票的最佳时机 IV
 * 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv
 */

#include <vector>
#include <algorithm>

using std::max;
using std::vector;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;
        vector<vector<int>> dp(2, vector<int>(2 * k + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= 2 * k; i++)
            if (i % 2 == 1)
                dp[0][i] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            for (int j = 1; j <= 2 * k; j++)
            {
                if (j % 2 == 1)
                    dp[1][j] = max(dp[0][j], dp[0][j - 1] - prices[i]);
                else
                    dp[1][j] = max(dp[0][j], dp[0][j - 1] + prices[i]);
                dp[0][j] = dp[1][j];
            }
        }
        return dp[1][k * 2];
    }
};
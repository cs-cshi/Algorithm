/**
 * 123. 买卖股票的最佳时机 III
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii
 */

#include <vector>
#include <algorithm>

using std::max;
using std::vector;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // dp[][0] 未持有，没有操作  dp[1][0] = dp[0][0]
        // dp[][1] 第一次买入       dp[1][1] = max(dp[0][1],dp[0][0]-prices[i])
        // dp[][2] 第一次卖出       dp[1][2] = max(dp[0][2],dp[0][1]+prices[i])
        // dp[][3] 第二次买入       dp[1][3] = max(dp[0][3],dp[0][2]-prices[i])
        // dp[][4] 第二次卖出       dp[1][4] = max(dp[0][4],dp[0][3]+prices[i])
        vector<vector<int>> dp(2, vector<int>(5, 0));
        // dp[0][0] = 0;
        dp[0][1] = -prices[0];
        // dp[0][2] = 0;
        dp[0][3] = -prices[0];
        // dp[0][4] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[1][0] = dp[0][0];
            dp[1][1] = max(dp[0][1], dp[0][0] - prices[i]);
            dp[1][2] = max(dp[0][2], dp[0][1] + prices[i]);
            dp[1][3] = max(dp[0][3], dp[0][2] - prices[i]);
            dp[1][4] = max(dp[0][4], dp[0][3] + prices[i]);
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
            dp[0][2] = dp[1][2];
            dp[0][3] = dp[1][3];
            dp[0][4] = dp[1][4];
        }
        return dp[1][4];
    }
};
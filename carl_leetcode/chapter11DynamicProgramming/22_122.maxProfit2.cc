/**
 * 122. 买卖股票的最佳时机 II
 * 给定一个数组 prices ，其中 prices[i] 表示股票第 i 天的价格。
 * 在每一天，你可能会决定购买或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以购买它，然后在 同一天 出售。
 * 返回 你能获得的最大利润 。
 * 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii
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
        if (prices.size() == 1)
            return 0;
        int cost = prices[0]; // 买入
        int profit = 0;       // 总利润
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < cost) // 没有利润，更新买入时间
            {
                cost = prices[i];
                continue;
            }
            profit += prices[i] - cost; // 有利润，卖出
            cost = prices[i];           // 当前再买入
        }
        return profit;
    }
    int maxProfit2(vector<int> &prices)
    {
        if (prices.size() == 1)
            return 0;
        // dp[i][0] ：第 i 天持有
        // dp[i][1] ：第 i 天不持有
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i])
        // dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i])

        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }
    
    int maxProfit3(vector<int> &prices)
    {
        // [][0] 持有
        // [][1] 不持有
        vector<vector<int>> dp(2, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[1][0] = max(dp[0][0], dp[0][1] - prices[i]);
            dp[1][1] = max(dp[0][1], dp[0][0] + prices[i]);
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }
        return dp[1][1];
    }
};
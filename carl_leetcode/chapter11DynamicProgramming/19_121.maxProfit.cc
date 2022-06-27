/**
 * 121. 买卖股票的最佳时机
 * 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 * 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
 * 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
 * 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
 */

#include <vector>
#include <algorithm>

using std::max;
using std::min;
using std::vector;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int low = __INT_MAX__;
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            low = min(low, prices[i]);
            maxProfit = max(maxProfit, prices[i] - low);
        }
        return maxProfit;
    }

    int maxProfit2(vector<int> &prices)
    {
        // dp[i][0] 第 i 天持有拥有的现金
        // dp[i][1] 第 i 天不持有拥有的现金

        // dp[i][0] = max(dp[i-1][0],-price[i])
        // dp[i][1] = max(dp[i-1][1],price[i]+dp[i-1][0])

        // dp[0][0] = -price[0]
        // dp[0][1] = 0

        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }

    int maxProfit3(vector<int> &prices)
    {
        // dp[i][0] 第 i 天持有拥有的现金
        // dp[i][1] 第 i 天不持有拥有的现金

        // dp[i][0] = max(dp[i-1][0],-price[i])
        // dp[i][1] = max(dp[i-1][1],price[i]+dp[i-1][0])

        // dp[0][0] = -price[0]
        // dp[0][1] = 0

        // vector<vector<int>> dp(prices.size(), vector<int>(2));
        vector<vector<int>> dp(2, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[1][0] = max(dp[0][0], -prices[i]);
            dp[1][1] = max(dp[0][1], dp[0][0] + prices[i]);
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }
        return dp[1][1];
    }
};
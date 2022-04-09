/**
 * 714. 买卖股票的最佳时机含手续费
 * 给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
 * 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
 * 返回获得利润的最大值。
 * 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
 * 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
 */

#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        // dp[i][]  第 i 天 j 状态所拥有的现金
        // 0：持有  1：不持有
        // 递推公式
        // dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i]-fee)
        // dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i])
        // 初始化
        vector<vector<int>> dp(prices.size(), vector<int>(2,0));
        dp[0][0] = -prices[0] - fee;
        for(int i = 1;i<prices.size();i++)
        {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i]-fee);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);
        }
        return dp[prices.size()-1][1];
    }
};
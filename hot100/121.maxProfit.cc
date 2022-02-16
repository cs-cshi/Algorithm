/*
给定一个数组 prices，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择某一天买入这只股票，并选择在未来的某一个不同的日子卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0。
*/
#include <vector>
#include <limits>
#include <algorithm>

using std::vector;
using std::numeric_limits;
using std::max;
using std::min;

/*
    类似于动规的思想
    一次遍历：
        min_price 记录遍历价格中的最小价格
        max_profit 记录当前遍历价格中最大利润
*/
int maxProfit(vector<int> &prices)
{
    int min_price = numeric_limits<int>::max();
    int max_profit = 0;

    for(int i = 0; i < prices.size();i++)
    {
        if(min_price > prices[i])
            min_price = prices[i];
        else if (prices[i] - min_price > max_profit)
            max_profit = prices[i] - min_price;
    }
    return max_profit;
}

int maxProfit(vector<int> &prices)
{
    int min_price = prices[0];
    int max_profit = 0;
    for(int i = 1;i<prices.size();i++)
    {
        min_price = min(prices[i],min_price);
        max_profit = max(max_profit,prices[i] - min_price);
    }
    return max_profit;
}
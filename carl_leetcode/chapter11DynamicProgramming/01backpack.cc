/**
 * 有n件物品和一个最多能背重量为w 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大。
 */

#include <vector>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::max;
using std::vector;

// 使用二维动规数组
int backpackProblem(vector<int> &weight, vector<int> &value, int bagWeight)
{
    vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));
    /*  dp 数组初始化为0
    for (int i = 0; i < weight.size(); i++)
        dp[i][0] = 0;
    */

    for (int j = 0; j <= bagWeight; j++)
    {
        if (j >= weight[0])
            dp[0][j] = value[0];
        else
            dp[0][j] = 0;
    }

    for (int i = 1; i < weight.size(); i++)
    {
        for (int j = 0; j <= bagWeight; j++)
        {
            if (j < weight[i]) // 背包剩余容量小于当前物品重量
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            cout << dp[i][j] << endl;
        }
    }
    return dp[weight.size() - 1][bagWeight];
}

// 使用一位动规数组
int backpackProblem2(vector<int> &weight, vector<int> &value, int bagWeight)
{
    vector<int> dp(bagWeight + 1, 0);

    for (int i = 0; i < weight.size(); i++)
    {
        for (int j = bagWeight; j >= weight[i]; j--)
        {
            dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    return dp[bagWeight];
}

int main()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    // int result = backpackProblem(weight, value, bagWeight);
    int result = backpackProblem2(weight,value,bagWeight);
    cout << "result : " << result << endl;
}
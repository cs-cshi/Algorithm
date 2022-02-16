/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。
*/

#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

// dp[i] = dp[i-1] + dp[i-2];
int climbStairs(int n)
{
    if (n < 1)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    vector<int> dp(n, 0);  // 动规数组初始化

    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];  // 动规式

    return dp[n - 1];
}

int main()
{
    // climbStairs(2);
}
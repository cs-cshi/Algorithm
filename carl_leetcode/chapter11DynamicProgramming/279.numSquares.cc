/**
 * 279. 完全平方数
 * 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
 * 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
 * 链接：https://leetcode-cn.com/problems/perfect-squares
 */

#include <vector>
#include <algorithm>

using std::min;
using std::vector;

class Solution
{
public:
    int numSquares(int n)
    {
        // dp[j] 和为 j 的完全平方数最少数量
        // dp[j] = min(dp[j],dp[j-i*i]+1)
        // dp[0] = 0, dp[] = __INT_MAX__
        // 遍历顺序，任意
        vector<int> dp(n + 1, __INT_MAX__);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++)
            for (int j = 0; j <= n; j++)
                if(j-i*i>=0)
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
        return dp[n] == __INT_MAX__ ? -1 : dp[n];
    }
};
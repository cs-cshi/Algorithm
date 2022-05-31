/**
 * 343. 整数拆分
 * 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
 * 返回 你可以获得的最大乘积 。
 */

#include <vector>
#include <algorithm>

using std::max;
using std::vector;

class Solution
{
public:
    int integerBreak(int n)
    {
        /**
         * dp[i], 正整数 i 拆分后最大乘积
         * dp[i] = max(dp[i], max((i-j)*j, dp[i-j]*j))
         *      (i-j)*j, 划分为 (i-j) + j。
         *      dp[i-j]*j，(i-j) 继续划分
         * dp[0] = 0, dp[1] = 0, dp[2] = 1
         */
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
            for (int j = 1; j < i - 1; j++)
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j)); // dp[i]，从当前 j(1~i-1) 中选择最大的 dp[i]

        return dp[n];
    }
};
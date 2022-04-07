/**
 * 70. 爬楼梯
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 */

#include <vector>

using std::vector;

class Solution
{

public:
    int climbStairs(int n)
    {
        return climbStairs2(n);
    }

    int climbStairs2(int n)
    {
        // dp[i] 爬到第 i 阶的方法数量
        // 递推公式：dp[i] = dp[i-1] + dp[i-2]
        // 初始化dp
        // 确定遍历顺序
        // 举例
        if (n < 2)
            return n;
        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i < n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n - 1];
    }

    int climbStairs3(int n)
    {
        if (n <= 2)
            return n;
        int pre = 1;
        int last = 2;
        int result = 0;

        for (int i = 2; i < n; i++)
        {
            result = pre + last;
            pre = last;
            last = result;
        }
        return result;
    }
};
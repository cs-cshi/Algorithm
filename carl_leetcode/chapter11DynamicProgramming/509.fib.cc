/**
 * 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
 *   - F(0) = 0，F(1) = 1
 *   - F(n) = F(n - 1) + F(n - 2)，其中 n > 1
 * 给定 n ，请计算 F(n) 。
 * 链接：https://leetcode-cn.com/problems/fibonacci-number
 */

#include <vector>

using std::vector;

class Solution
{
public:
    int fib(int n)
    {
        // dp[i]  第i个数的斐波那契数
        vector<int> dp(n + 1);
        // 递推公式：dp[i] = dp[i-1]+dp[i-2]
        // 初始化dp 数组
        if (n < 2)
            return n;
        dp[0] = 0;
        dp[1] = 1;
        // 确定遍历顺序
        // 举例推导

        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }

    int fib2(int n)
    {
        if (n < 2)
            return n;

        int pre = 0;
        int last = 1;
        int result = 0;
        for (int i = 2; i <= n; i++)
        {
            result = pre + last;
            pre = last;
            last = result;
        }
        return result;
    }
};
/**
 * 494. 目标和
 * 给你一个整数数组 nums 和一个整数 target 。
 * 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
 *     例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 * 链接：https://leetcode-cn.com/problems/target-sum
 */

#include <vector>
#include <algorithm>

using std::abs;
using std::vector;

class Solution
{
public:
    /**
     * x ：数字前添加加号+ 的总和
     * y ：数字前添加减号- 的总和
     * x+y = sum    x-y = target   x = (sum+target)/2;
     */
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if (target > abs(sum) || (sum + target) % 2 == 1)
            return 0;

        int plusTarget = (sum + target) / 2;
        vector<int> dp(plusTarget + 1, 0); // dp[i]，和为 i 有 dp[i] 种方法
        // dp[j] += dp[j-nums[i]]
        dp[0] = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = plusTarget; j >= nums[i]; j--)
                dp[j] += dp[j - nums[i]];
        }
        return dp[plusTarget];
    }
};
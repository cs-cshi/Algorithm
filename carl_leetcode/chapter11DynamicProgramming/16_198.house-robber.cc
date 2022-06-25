/**
 * 198. 打家劫舍
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
 * 链接：https://leetcode.cn/problems/house-robber
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

    int rob(vector<int>& nums) {
        // dp[i], 到第 i 号房最多能偷窃的金额
        // dp[i] = max(dp[i-2] + nums[i], dp[i-1] )
        // dp[0] = nums[0], dp[1] = max(nums[0] ,nums[1])
        // 正序
        // 1,2,4,3

        int len = nums.size();
        if(len == 0)
            return -1;
        
        if(len == 1)
            return nums[0];

        
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < len; i++)
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        return dp[len-1];
    }

    int rob2(vector<int> &nums)
    {
        // dp[i], 到第 i 号房最多能偷窃的金额
        // dp[i] = max(dp[i-2], dp[i-3]) + nums[i]
        // dp[0] = nums[0], dp[1] = nums[1], dp[2] = dp[0] + nums[2]
        // 正序
        // 1,2,4,3

        int len = nums.size();
        if (len == 1)
            return nums[0];
        else if (len == 2)
            return max(nums[0], nums[1]);

        vector<int> dp(len);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = dp[0] + nums[2];
        for (int i = 3; i < len; i++)
            dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
        return max(dp[len - 1], dp[len - 2]);
    }
};
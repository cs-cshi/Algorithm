/**
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 子数组 是数组中的一个连续部分。
 */

#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // 连续子数组，动规
        // dp[i] : 以 i 结尾子串最大和
        if (nums.size() == 1)
            return nums[0];

        vector<int> dp(nums.size(), 0);
        int result = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(dp[i], result);
        }
        return result;
    }

    int maxSubArray2(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int curMax = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            curMax = max(curMax + nums[i], nums[i]);
            ans = max(curMax, ans);
        }
        return ans;
    }
};
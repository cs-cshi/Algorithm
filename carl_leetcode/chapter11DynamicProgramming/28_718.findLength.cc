/**
 * 718. 最长重复子数组
 * 给两个整数数组 nums1 和 nums2，返回两个数组中公共的 、长度最长的子数组的长度 。
 * 链接：https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/
 */

#include <vector>
#include <algorithm>

using std::max;
using std::vector;

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> dp(nums1.size() + 1, 0);
        int result = 0;
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = nums2.size(); j > 0; j--)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[j] = dp[j - 1] + 1;
                else
                    dp[j] = 0; // 注意这里不相等的时候要有赋0的操作
                result = max(result, dp[j]);
            }
        }
        return result;
    }

    int findLength2(vector<int> &nums1, vector<int> &nums2)
    {
        // dp[i][j] ：以 nums1 以 i-1 结尾与 nums2 以 j-1  结尾最长公共子串长度
        // dp[i][j] = dp[i-1][j-1] + 1, nums[i] == nums[j]
        // dp[i][j] = 0, nums[i] != nums[j]
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        int result = 0;
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};
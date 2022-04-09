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
                    dp[j] = 0;
                result = max(result, dp[j]);
            }
        }
        return result;
    }
};
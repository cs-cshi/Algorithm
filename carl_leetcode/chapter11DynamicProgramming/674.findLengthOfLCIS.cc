/**
 * 674. 最长连续递增序列
 * 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
 * 连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
 * 链接：https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence
 */

#include <vector>
#include <algorithm>

using std::max;
using std::vector;

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int left = 0;
        int maxLength = 1;
        for (int right = 1; right < nums.size(); right++)
        {
            if (nums[right] > nums[right - 1])
                maxLength = max(maxLength, right - left + 1);
            else
                left = right;
        }
        return maxLength;
    }
};
/**
 * 53. 最大子数组和
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 子数组 是数组中的一个连续部分。
 */

#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int currentSum = nums[0];
        int maxSum = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            currentSum = max(currentSum+nums[i],nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};
/**
 * 977. 有序数组的平方
 * 给你一个按非递减顺序排序的整数数组 nums，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
 * 链接 : https://leetcode-cn.com/problems/squares-of-a-sorted-array/
 */

#include <vector>

using namespace ::std;

class Solution
{
public:
    /**
     * 双指针法。考虑负数的存在，nums 中元素的平方的大小将是严格从两端向中间递减
    */
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> result(nums.size());
        int left = 0;
        int right = nums.size();
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[right] * nums[right] > nums[left] * nums[left])
            {
                result[i] = nums[right] * nums[right];
                right--;
            }
            else
            {
                result[i] = nums[left] * nums[left];
                left++;
            }
        }
        return result;
    }
};
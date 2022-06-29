/**
 * 300. 最长递增子序列
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
 * 链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
 */

#include <vector>
#include <algorithm>
#include <iostream>

using std::max;
using std::vector;
using std::cout;
using std::endl;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // 背包问题？类似于
        // dp[i]：数组中 i 位置的最长增长子序列长度
        // dp[i] = max(dp[i],dp[j]+1),j∈[0,i)

        if (nums.size() <= 1)
            return nums.size();

        vector<int> dp(nums.size(), 1);
        // dp[0]=1;
        int result=0;
        for (int i = 1; i < nums.size(); i++)
        {
            cout << "i = " << i << " : ";
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result,dp[i]);
        }
        return result;
    }
};

int main()
{
    vector<int> nums={1,3,6,7,9,4,10,5,6};
    Solution solution;
    solution.lengthOfLIS(nums);
}
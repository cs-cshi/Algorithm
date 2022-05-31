/**
 * 给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：
 *   - 选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
 * 重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
 * 以这种方式修改数组后，返回数组 可能的最大和 。
 * 链接：https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int i = 0;

        // 从小到大修改每一个负数
        while (i < nums.size() && nums[i] < 0 && k--)
        {
            nums[i] = -nums[i];
            i++;
        }

        // 负数全部修改完成，还需要修改 k 次
        if (k > 0 && k % 2 == 1)    
        {
            if (i == 0) // 全为正
                nums[i] = -nums[i];
            else if (i >= nums.size())  // 转换次数大于数组元素个数
                nums[i - 1] = -nums[i - 1];
            else if (nums[i] < 0 || nums[i - 1] >= nums[i]) 
                nums[i] = -nums[i];
            else
                nums[i - 1] = -nums[i - 1];
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            ans += nums[i];

        return ans;
    }
};
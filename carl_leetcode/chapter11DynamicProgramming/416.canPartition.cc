/**
 * 416. 分割等和子集
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 */

#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::vector;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if (sum % 2 == 1)
            return false;
        return backTracking(nums, 0, 0, sum / 2);
    }

    bool backTracking(vector<int> &nums, int index, int curSum, int target)
    {
        if (curSum == target)
        {
            if (index == nums.size())
                return false;
            return true;
        }

        if (curSum > target)
            return false;

        for (int i = index; i < nums.size(); i++)
        {
            curSum += nums[i];
            if (backTracking(nums, index, curSum, target))
                return true;
            curSum -= nums[i];
        }
        return false;
    }

    bool backpack(vector<int> &nums)
    {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if (sum % 2 == 1)
            return false;
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--)
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
        if (dp[target] == target)
            return true;
        return false;
    }

    bool canPartition2(vector<int> &nums)
    {
        // 1.dp[j] 容量为 j 的背包可以凑成的子集总和
        // 2. 递归公式：dp[j] = max(dp[j],dp[j-weight[i]]+value[i])
        // 3. 初始化
        // 4. 遍历顺序
        // 5. 举例验证
        int sum = 0;
        for (int num : nums)
            sum += num;

        if (sum % 2 == 1)
            return false;

        int target = sum / 2;
        vector<int> dp(target + 1,0);
        // dp[0] = 0; // 都是正整数，且相加
        for(int i = 0;i<nums.size();i++)
        {
            for(int j = target;j>=nums[i];j--)
                dp[j] = max(dp[j],dp[j-nums[i]]+nums[i]);
        }
        return dp[target] == target;
    }
};

int main()
{
    vector<int> nums = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 99, 97};
    Solution solution;
    bool result = solution.canPartition(nums);
    cout << result << endl;
}
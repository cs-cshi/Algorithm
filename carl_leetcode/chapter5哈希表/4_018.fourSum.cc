/**
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] 
 * （若两个四元组元素一一对应，则认为两个四元组重复）：
 *      0 <= a, b, c, d < n
 *      a、b、c 和 d 互不相同
 *      nums[a] + nums[b] + nums[c] + nums[d] == target
 * 你可以按 任意顺序 返回答案 。
 * 链接：https://leetcode-cn.com/problems/4sum
 */

#include <vector>
#include <algorithm>

using std::sort;
using std::vector;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) // 第一个数 a 去重，a 从第二个数开始计算,注意题干是索引互不相同
                continue;

            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) // 第二个数去重
                    continue;

                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    // 只有当找到一组 a + b + c + d = target 后再对第三个数和第四个数去重
                    if (nums[i] + nums[j] < target - (nums[left] + nums[right]))
                        left++;
                    else if (nums[i] + nums[j] > target - (nums[left] + nums[right]))
                        right--;
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (right > left && nums[left] == nums[left + 1]) // 第三个数去重
                            left++;
                        while (right > left && nums[right] == nums[right - 1]) // 第四个数去重
                            right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }

    vector<vector<int>> fourSum2(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        // a = nums[i], b = nums[j], c = nums[left], d = nums[right]
        for (int i = 0; i < nums.size(); i++)
        {
            // a 去重
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // b 去重
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    if (nums[i] + nums[j] > target - nums[left] - nums[right])
                        right--;
                    else if (nums[i] + nums[j] < target - nums[left] - nums[right])
                        left++;
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (right > left && nums[left] == nums[left + 1])
                            left++;
                        while (right > left && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};
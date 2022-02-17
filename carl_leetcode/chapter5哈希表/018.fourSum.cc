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
            if (i > 0 && nums[i] == nums[i - 1]) // 第一个数 a 去重
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
};
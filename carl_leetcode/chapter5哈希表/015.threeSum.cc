#include <vector>
#include <unordered_set>
#include <algorithm>

using std::sort;
using std::unordered_set;
using std::vector;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            // 排序后，三元组第一个元素不能大于 0
            if (nums[i] > 0)
                break;

            // 第一个元素 a 去重
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            unordered_set<int> set;

            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) // 三元组第二个元素 b 去重
                    continue;

                int c = 0 - nums[i] - nums[j];

                if (set.find(c) == set.end())
                {
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c);
                }
                else
                    set.insert(nums[j]);
            }
        }
        return result;
    }

    // 双指针法
    vector<vector<int>> threeSum2(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break;

            if (i > 0 && nums[i] == nums[i - 1]) // 第一个数 a 去重
                continue;

            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if ((nums[i] + nums[left] + nums[right]) > 0)
                    right--;
                else if ((nums[i] + nums[left] + nums[right]) < 0)
                    left++;
                else{
                    result.push_back({nums[i], nums[left], nums[right]});
                    while(right > left && nums[right] == nums[right-1])
                        right--;
                    while(right > left && nums[left] == nums[left+1])
                        left++;
                    right--;
                    left++;
                }
                
            }
        }
    }
};
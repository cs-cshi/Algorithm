/**
 * 三数之和
 */
#include <vector>
#include <algorithm>

using namespace std;

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
            else
            {
                result.push_back({nums[i], nums[left], nums[right]});
                // 注意是 right - 1 和 left  + 1，当前位置与下一个位置判断，不满足 while 时指针不会移动
                while (right > left && nums[right] == nums[right - 1])
                    right--;
                while (right > left && nums[left] == nums[left + 1])
                    left++;
                right--;
                left++;
            }
        }
    }
}
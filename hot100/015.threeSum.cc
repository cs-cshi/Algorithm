// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans = {};

    if (nums.size() < 3)
        return {};

    sort(nums.begin(), nums.end()); // 升序排序

    if (nums[0] > 0) // 所有元素都大于0，不可能有结果
        return {};

    for (size_t i = 0; i < nums.size(); i++) // first 元素遍历
    {
        if (i > 0 && nums[i] == nums[i - 1]) // first 元素去重
            continue;

        int left = i + 1;            // second 元素
        int right = nums.size() - 1; // third 元素

        while (left < right)
        {
            if (nums[left] + nums[right] == -nums[i]) // 三个元素之和 == 0
            {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1]) // second 元素去重
                    left++;
                while (left < right && nums[right] == nums[right + 1]) // third 元素去重
                    right--;
            }
            else if (nums[left] + nums[right] > -nums[i]) // second third 之和太大， third 左移
                right--;
            else
                // second third 之和太小， second 左移
                left++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {0, 0, 0};
    vector<vector<int>> ans = threeSum(nums1);
    for (auto items : ans)
    {
        for (auto item : items)
            cout << item << "  ";
        cout << endl;
    }
}
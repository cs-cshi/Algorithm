/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
*/

#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

// 二分查找
vector<int> searchRange(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    if (!nums.size())
        return {-1, -1};

    if (nums.size() == 1)
    {
        // return target == nums[0] ? {0, 0} : {-1, -1};
        if (target == nums[0])
            return {0, 0};
        return {-1, -1};
    }

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            int begin = mid;
            int end = mid;

            // 先判断是否越界，再判断 nums[end]，否则 nums[end] 可能越界
            while (end < nums.size() && nums[end] == target)
                end++;

            while (begin >= 0 && nums[begin] == target)
                begin--;

            return {begin + 1, end - 1};
        }

        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return {-1, -1};
}

int main()
{
    // vector<int> nums = {5,7,7,8,8,10};
    vector<int> nums = {1, 1};
    int target = 1;
    vector<int> result = searchRange(nums, target);
    for (int i : result)
        cout << "  " << i;
    cout << endl;
}
/**
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 */

#include <vector>

using std::vector;

int search(vector<int> &nums, int target)
{
    if (nums.size() <= 0)
        return -1;

    // 左闭右闭区间 []
    int left = 0;
    int right = nums.size() - 1;

    while (right >= left)
    {
        // 防止溢出
        // int mid = (right + left) / 2; // 索引
        int mid = (right - left) / 2 + left;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    if(nums.size() <= 0)
        return -1;

    // 左闭右开 [)
    int left = 0;
    int right = nums.size();
    while(left < right)
    {
        int mid = left + (right - left) >> 1;
        if(nums[mid]==target)
            return mid;
        else if (nums[mid] > target)
            right = mid;
        else
            left = mid + 1;
    }
    return -1;
}
/*
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// 二分查找算法，也叫折半查找，用于旋转数组的情况
int binarySearch(vector<int> nums, int start, int end, int target)
{
    if (end - start < 0) //全部遍历完成，无结果
        return -1;

    int mid = start + (end - start) / 2;

    if (nums[mid] == target)
        return mid;

    // 注意，mid 向下取整，当 start == mid 时，应该是旋转点位于 mid 右侧的情况
    if (nums[start] <= nums[mid]) // mid 位于旋转点左侧
    {
        // 注意小于等于号，nums[start]位于左侧，因此 target == nums[start]的情况要放在右侧
        if (target < nums[mid] && target >= nums[start]) 
            return binarySearch(nums, start, mid - 1, target);
        else // 位于右侧
            return binarySearch(nums, mid + 1, end, target);
    }
    else
    {
        // 注意小于等于号，nums[end]位于右侧，因此 target == nums[end]的情况要放在右侧
        if (target > nums[mid] && target <= nums[end])       
            return binarySearch(nums, mid + 1, end, target); //右侧
        else
            return binarySearch(nums, start, mid - 1, target);
    }
}

int search(vector<int> &nums, int target)
{
    // int mid = nums.size() / 2;
    // int start = 0;
    // int end = nums.size() - 1;

    if (!nums.size())
        return -1;

    if (nums.size() == 1)
        return nums[0] == target ? 0 : -1;

    return binarySearch(nums, 0, nums.size() - 1, target);

    /*
    if (target > nums[0]) // target 在左侧升序序列中
    {
        while (target > nums[mid]) // mid 位于右侧升序，将其移至左侧升序序列尾部
            mid--;
        while (nums[mid + 1] > target) // mid 位于左侧， target 位于 mid 右侧
            mid++;

        return binarySearch(nums, start, mid, target);
    }
    else if (target < nums[0]) // target 在右侧升序序列中
    {
        while (target > nums[mid]) // mid 位于左侧升序，将其移至右侧升序
            mid++;
        return binarySearch(nums, mid, end, target);
    }
    else
        return 0;
    */
}

int main()
{
    // vector<int> nums = {2};
    vector<int> nums = {3,1};
    int target = 1;
    int answer = search(nums, target);
    cout << answer << endl;
    return 0;
}
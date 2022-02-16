/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using std::cout;
using std::endl;
using std::max;
using std::swap;
using std::unordered_set;
using std::vector;

// 分组重排
int partion(vector<int> &nums, int begin, int end)
{
    int mid_val = nums[end];
    int i = begin - 1;
    for (int j = begin; j < end; j++)
    {
        if (nums[j] < mid_val)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[end]);
    return i + 1;
}

// 快排
void quicksort(vector<int> &nums, int begin, int end)
{
    if (begin < end)
    {
        int mid = partion(nums, begin, end);
        quicksort(nums, begin, mid - 1);
        quicksort(nums, mid + 1, end);
    }
}

int longestConsecutive2(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    quicksort(nums, 0, nums.size() - 1);
    int start_num = nums[0];
    int len = nums.size();
    int cur_count = 1;
    int ans = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
            continue;
        else if (nums[i] == nums[i - 1] + 1)
            cur_count++;
        else
        {
            ans = max(ans, cur_count);
            cur_count = 1;
        }
    }
    ans = max(ans, cur_count);
    return ans;
}

// 不进行排序，使用 hash
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> nums_set;    // hashset，去重
    for (const int &num : nums)
        nums_set.insert(num);

    int ans = 0;

    for (const int &num : nums_set)
    {
        if (!nums_set.count(num - 1))  // 如果当前 num -1 不存在，说明是新的连续串，开始计算连续串长度
        {
            int current_count = 1;  // 当前连续串长度
            int current_num = num;

            while (nums_set.count(current_num + 1))
            {
                current_count++;
                current_num++;
            }
            ans = max(ans, current_count);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    longestConsecutive(nums);
}
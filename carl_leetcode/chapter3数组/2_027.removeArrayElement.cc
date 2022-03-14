/**
 * 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
 * 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 */
#include <vector>

using std::vector;

// 快慢指针，不会更改原数组元素顺序
int removeElement(vector<int> &nums, int val)
{
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
    {
        if (val != nums[fastIndex])
            nums[slowIndex++] = nums[fastIndex];
    }
    // 不需要 +1， slowIndex++ 后，指向的是实际数组的后一个位置
    return slowIndex;
}

// 首尾双指针，能避免不必要的移动，但会更改原数组顺序
int removeElement(vector<int> &nums, int val)
{
    int firstIndex = 0;
    int lastIndex = nums.size() - 1;

    while (firstIndex <= lastIndex)
    {
        if (nums[firstIndex] == val)
        {
            // 实际上这里可以不交换，直接赋值替代，题目要求只要保证不等于 val 的值在数组前面部分即可
            int temp = nums[firstIndex];
            nums[firstIndex] = nums[lastIndex];
            nums[lastIndex] = nums[firstIndex];
            lastIndex--;
        }
        else
            firstIndex++;
    }
    return firstIndex;
}

int main()
{
    return 0;
}
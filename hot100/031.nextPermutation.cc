/*
实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须 原地 修改，只允许使用额外常数空间。

*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::reverse;
using std::vector;

// 交换两个数字，一个数与另一个数异或两次，得到的还是原来的数
void swapTwoNumber(int *num1, int *num2)
{
    if (*num1 == *num2) // 两个相同数异或后为0
        return;

    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2; // (*num1 ^ *num2) ^ *num2
    *num1 = *num1 ^ *num2; // (*num1 ^ *num2) ^ *num1  // 此刻的 num2 已经是 num1的值了
}

// 获取 下一个排列
void nextPermutation(vector<int> &nums)
{
    if (nums.size() <= 1)
        return;

    int i = nums.size() - 2; // 从右至左，第一个降序的数
    int k = nums.size() - 1;

    // 从后往前，寻找第一个升序的相邻两数，说明不满足的都是降序
    while (i >= 0 && nums[i] >= nums[i + 1]) // i > 0，防止越界
        i--;

    // 如果 i < 0，说明 nums[0] >= nums[1] 也成立，即整个序列都是降序，无下一个满足条件序列
    if (i >= 0)
    {
        // 寻找 nums[i] 后面序列中比 nums[i] 大的数中最的小数
        while (k > 0 && nums[i] >= nums[k])
            k--;

        swapTwoNumber(&nums[i], &nums[k]);
    }
    // nums.begin() 是 nums 的第一个，j 是索引，nums.begin() + j 实际上是第 j 个数
    reverse(nums.begin() + i + 1, nums.end());
}

int main()
{
    // vector<int> nums = {1, 2, 3, 4, 5, 6};
    vector<int> nums = {5,1,1};
    nextPermutation(nums);
    // reverse(nums.begin() + 1, nums.end());
    for (int num : nums)
        cout << "  " << num;
    cout << endl;
    return 0;
}
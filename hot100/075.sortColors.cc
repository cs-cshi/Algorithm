/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
*/

#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

// 遍历两边，第一遍将0换至合适位置，第二次将1换至合适位置
void sortColors(vector<int> &nums)
{
    if (nums.size() == 1)
        return;

    int begin = 0;
    int end = nums.size() - 1;

    // 先将 0 划分到正确位置
    while (begin < end)
    {
        if (nums[begin] == 0)
        {
            begin++;
            continue;
        }

        while (nums[end] != 0 && begin < end)
            end--;

        // 交换 nums[begin] 和 nums[end]，不能用异或，值有0

        // 异或涉及内存6次读写，效率比临时变量低
        // nums[begin] = nums[begin] ^ nums[end];
        // nums[end] = nums[begin] ^ nums[end];
        // nums[begin] = nums[begin] ^ nums[end];

        if (begin < end)
        {
            int temp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = temp;
            begin++;
        }
    }

    end = nums.size() - 1;

    while (begin < end)
    {
        if (nums[begin] == 1)
        {
            begin++;
            continue;
        }

        while (nums[end] != 1 && begin < end)
            end--;

        // 交换 nums[begin] 和 nums[end]

        // nums[begin] = nums[begin] ^ nums[end];
        // nums[end] = nums[begin] ^ nums[end];
        // nums[begin] = nums[begin] ^ nums[end];

        if (begin < end)
        {
            int temp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = temp;
            begin++;
        }
    }
}

// 使用双指针，pre 指向 0 的后一个位置，last 指向 1 的后一个位置
// i 遍历数组
// 当nums[i] == 0 时，
//      如果 nums[pre]==1，将 nums[i] 放至 nums[pre]，nums[pre] 放至 nums[last]，nums[last] 放至 nums[i]
//      否则交换 nums[i] 和 nums[pre】
//      pre 和 last 都后移一位
// 当 nums[i] == 1 时，
//      交换 nums[i] 和 nums[last]，last 后移一位
void sortColors2(vector<int> &nums)
{
    if (nums.size() == 1)
        return;

    int p0 = 0;
    int p1 = 0;
    int temp = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == 0)
        {
            temp = nums[p0];
            nums[p0] = nums[i];
            if (temp == 1)
            {
                nums[i] = nums[p0];
                nums[p1] = temp;
            }else
                nums[i] = temp;
            p0++;
            p1++;
        }
        else if (nums[i] == 1)
        {
            temp = nums[p1];
            nums[p1] = nums[i];
            nums[i] = temp;
            p1++;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors2(nums);
    for (int num : nums)
        cout << num << "  ";
    cout << endl;
    return 0;
}
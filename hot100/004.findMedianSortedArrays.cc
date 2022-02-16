// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

#include <vector>
#include <iostream>

using std::min;
using std::vector;
using std::cout;
using std::endl;

double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2)
{
    int indexSum = nums1.size() + nums2.size();
    int midIndex = indexSum / 2;
    vector<int> nums; // 合并 num1,num2
    unsigned i = 0;   // 遍历 num1 的索引
    unsigned j = 0;   // 遍历 num2 的索引
    unsigned k = 0;   // 合并序列的索引

    // 其中一个数组为空
    if (nums1.size() == 0)
        nums = nums2;
    if (nums2.size() == 0)
        nums = nums1;

    nums.resize(indexSum); // 两个数组都不为空，调整合并数组大小

    // 遍历两个待合并数组，直至其中一个数组遍历完
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] > nums2[j])
        {
            nums[k] = nums2[j];
            j++;
        }
        else
        {
            nums[k] = nums1[i];
            i++;
        }
        k++;
    }

    while (i < nums1.size())
    {
        nums[k] = nums1[i];
        i++;
        k++;
    }

    while (j < nums2.size())
    {
        nums[k] = nums2[j];
        j++;
        k++;
    }

    // 返回合并数组的中位数
    if (indexSum % 2 != 0) // 奇
        return nums[midIndex];
    else // 偶
        return (nums[midIndex] + nums[midIndex - 1]) / 2.0;
}

// 我们不需要合并的数组，实际上只要知道中位数在就行了。
// 开始的思路是进行一次完整的遍历，当到达中位数这个位置时就返回，但这里对奇偶以及边界判断会很麻烦，代码很乱，并且时间复杂度与第一种方法不变。
// 可以在循环处判断到中位数那个位置，同时记录下上一次遍历和这一次遍历的结果。对于奇，中位数就是当前位置，对于偶，就是与上一次结果的平均。
double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2)
{
    int indexSum = nums1.size() + nums2.size();
    int midIndex = indexSum / 2 + 1; // 中位数的位置，非索引
    int left = 0;                    // 上一轮的值
    int right = 0;                   // 当前遍历的值
    int start1 = 0;                  // 第一个数组遍历索引
    int start2 = 0;                  // 第二个数组遍历索引
    for (unsigned i = 0; i < midIndex; i++)
    {
        left = right;
        // 需要先判断 nums1 是否为空，否则当 nums1 为空时，nums1[start1] 将会越界
        // 后部分需要先判断 start2 是否已经遍历完或者为空，否则 nums2[start2]会越界
        if (start1 < nums1.size() && (start2 >= nums2.size() || nums1[start1] < nums2[start2]))
        {
            right = nums1[start1];
            start1++;
        }
        else
        {
            right = nums2[start2];
            start2++;
        }
    }

    if (indexSum % 2 != 0)
    {
        return right;
    }
    else
    {
        return (left + right) / 2.0;
    }
}

// 用的是二分法查找两个数组中第 k 小的数
double findMedianSortedArrays3(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    // 将奇偶统一。如果总数是奇数，那个 left == right
    int left = (n + m + 1) / 2;
    int right = (n + m + 2) / 2;
    // 返回第 left 小 和第 right 小的数的平均值
    return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) / 2.0;
}

// 假设两个有序数组分别是 A 和 B。要找到第 k 个元素，我们可以比较 A[k/2−1] 和 B[k/2−1]，其中 / 表示整数除法。
// 由于 A[k/2−1] 和 B[k/2−1] 的前面分别有 A[0..k/2−2] 和 B[0..k/2−2]，即 k/2−1 个元素，对于 A[k/2−1]
// 和 B[k/2−1] 中的较小值，最多只会有 (k/2−1)+(k/2−1)≤k−2 个元素比它小，那么它就不能是第 k 小的数了，可以全部排除。
// start、end 是索引，k指第几小 Kth
int getKth(vector<int> nums1, int start1, int end1, vector<int> nums2, int start2, int end2, int k)
{
    int len1 = end1 - start1 + 1;
    int len2 = end2 - start2 + 1;

    // 递归出口：其中一个数组为空，或者 k = 1，即求最小的数
    // 确保当存在数组为空时，一定是 nums1
    if (len2 < len1) // 两个数组交换位置
        return getKth(nums2, start2, end2, nums1, start1, end1, k);

    if (len1 == 0)
        return nums2[start2 + k - 1];

    if (k == 1) // 即返回最小的一个数
        return min(nums1[start1], nums2[start2]);

    // 取两个数组第 k/2 的索引。还需要判断 k/2 是否超过数组长度 len 的情况
    int i = start1 + min(k / 2, len1) - 1;
    int j = start2 + min(k / 2, len2) - 1;

    // 从找第 k 小变成了 第 (k - 弃掉数个数)小了
    // 弃掉数可能是 k/2，也有可能是 len 长度
    if (nums1[i] > nums2[j])
    {
        return getKth(nums1, start1, start2, nums2, j + 1, end2, k - (j - start2 + 1));
    }
    else
    {
        return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
    }
}

int main()
{
    vector<int> nums1 = {0, 0, 0};
    vector<int> nums2 = {};
    double result = findMedianSortedArrays2(nums1, nums2);
    cout << result << endl;
}

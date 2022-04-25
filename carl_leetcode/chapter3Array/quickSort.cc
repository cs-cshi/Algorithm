/**
 * 快速排序
 */
#include <vector>
#include <algorithm>

using namespace std;

// 随机选取主元位置
int randomPartition(vector<int> &arr, int left, int right)
{
    int i = (random() % right - left + 1) + left;
    swap(arr[left], arr[i]);
    return partition(arr, left, right);
}

// 以主元为界，左右划分
int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[left];
    int i = left + 1, j = right;
    while (true)
    {
        // 向右遍历扫描
        while (i <= j && arr[i] <= pivot)
            i++;

        // 向左遍历扫描
        while (i <= j && arr[j] >= pivot)
            j--;

        if (i >= j)
            break;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    // 把 arr[j]和主元交换
    arr[left] = arr[j];
    arr[j] = pivot;
    return j;
}

//[left, right]
void quickSort(vector<int> &nums, int left, int right)
{
    if (left < right)
    {
        int mid = randomPartition(nums, left, right);
        quickSort(nums, left, mid - 1);
        quickSort(nums, mid + 1, right);
    }
}

vector<int> sortArray(vector<int> &nums)
{
    quickSort(nums, 0, nums.size() - 1);
    return nums;
}

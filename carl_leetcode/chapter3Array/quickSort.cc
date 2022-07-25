/**
 * 快速排序
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    int randomPartition(vector<int> &arr, int left, int right)
    {
        int i = (rand() % (right - left + 1)) + left;
        // cout << left << " : " << i <<  "  ：  "<< right << endl;
        swap(arr[i], arr[left]);
        return partition(arr, left, right);
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

            swap(arr[i], arr[j]);
        }
        // 把 arr[j]和主元交换
        arr[left] = arr[j];
        arr[j] = pivot;
        return j;
    }
};
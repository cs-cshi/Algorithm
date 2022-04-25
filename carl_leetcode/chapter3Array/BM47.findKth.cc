/**
 * M47 寻找第K大
 * 有一个整数数组，请你根据快速排序的思路，找出数组中第 k 大的数。
 * 给定一个整数数组 a ,同时给定它的大小n和要找的 k ，请返回第 k 大的数(包括重复的元素，不用去重)，保证答案存在。
 * 要求：时间复杂度 O(nlogn)，空间复杂度 O(1)
 * 链接：https://www.nowcoder.com/practice/e016ad9b7f0b45048c58a9f27ba618bf?tpId=295&tqId=44581&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        // write code here
        int k = n - K;
        return quickSort(a, 0, n-1, k);
    }
    
    int quickSort(vector<int> &nums, int left, int right, int k)
    {
        int mid = randomPartition(nums,left, right);
        if(mid == k)
            return nums[mid];
        else if ( mid > k-1 )
            return quickSort(nums, left, mid - 1, k);
        else
            return quickSort(nums, mid + 1, right, k);
        
    }
    
    int randomPartition(vector<int> &nums, int left, int right)
    {
        int random_num = (random() % (right - left + 1)) + left;
        swap(nums[left],nums[random_num]);
        return partition(nums, left, right);
    }

    
    int partition(vector<int> &nums, int left, int right)
    {
        int pivot = nums[left];
        int i = left + 1, j = right;
        
        while(true){
            while(i <= j && nums[i] <= pivot)
                i++;
        
            while(i <= j && nums[j] >= pivot)
                j--;
        
            if(i > j)
                break;
        
            swap(nums[i],nums[j]);
        }
        swap(nums[left],nums[j]);
        
        return j;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {9,9,12,5,10,6};
    cout <<  solution.findKth(nums,6,3) << endl;
}
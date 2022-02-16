/*
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
*/

#include <iostream>
#include <vector>

using namespace std;

// 利用 鸠占鹊巢 思想，把 鹊 交换至正确的巢，发现正确的巢已经被鹊占，说明重复
// 会修改原数组，O(n)
int findRepeatNumber2(vector<int> &nums)
{
    // 题目已经给定了 nums.size() > 2
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > nums.size())
            return -1;

        while (nums[i] != i)
        {
            if(nums[i] == nums[nums[i]])
                return nums[i];

            swap(nums[i], nums[nums[i]]);
        }
    }
    return -1;
}

// 计算 [start, end] 这个区间的数在 nums 中出现的次数
int countRange(const vector<int> nums, int start, int end)
{
    if( nums.size() <= 0 )
        return 0;
    
    int count = 0;
    for(int i = 0; i< nums.size(); i++)
    {
        if(nums[i] >= start && nums[i] <= end)
            count++;
    }
    return count;
}

int findRepeatNumber(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    
    while(end >= start)
    {
        int mid = ((end - start) >> 1) + start;
        int count = countRange(nums, start, mid);

        // 退出条件
        if(start == end)
        {
            if(count > 1)
                return start;
            else 
                break;
        }

        // 分治
        if(count > (mid - start + 1))
            end = mid;
        else
            start = mid + 1;
    }
    
    return -1;
}




int main()
{
    vector<int> nums{ 1,2,3,4,4};
    int res = findRepeatNumber2(nums);
    cout << res << endl;
    return 0;
}
/**
 * 169. 多数元素（hot 100）
 * 难度：easy
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 链接：https://leetcode-cn.com/problems/majority-element
 */

#include <vector>

using namespace std;

/**
 * 多数元素出现次数大于 n/2，说明多数元素出现次数大于其他元素出现次数的总和
 * 两两删除思想，先将首位元素设为候选，依次遍历，当两个元素不相等时，且候选元素次数都抵消完时，替换候选元素
 */
int majorityElement(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    int count = 1;
    int candidate = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if(nums[i] == candidate)    // 候选元素个数增加
            count++;
        else    // 抵消一个候选元素
            count--;

        if(count == 0){ // 重置候选元素
            candidate = nums[i];
            count = 1;
        }
    }
    return candidate;
}

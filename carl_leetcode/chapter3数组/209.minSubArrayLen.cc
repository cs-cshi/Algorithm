/**
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 * 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 */
#include <vector>

using std::vector;


/**
 * 滑动窗口 3 要素：
 * 1. 窗口内元素
 * 2. 如何移动窗口起始位置？
 * 3. 如何移动窗口终止位置？
 * 
 * 本题：
 * 1. 窗口内是和大于等于 target 的元素
 * 2. 移动起始位置：当前窗口和大于等于 target
 * 3. 移动终止位置：当前窗口和小于 target
 * 通过终止位置遍历指针
 */ 
int minSubArrayLen(int target, vector<int>& nums) {
    int result = __INT32_MAX__;
    int sum = 0;
    int subLength = 0;
    int startIndex = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        while ( sum >= target ){
            subLength = i - startIndex + 1;
            result = result < subLength ? result : subLength;
            sum -= nums[startIndex++];
        }
    }
    return result == __INT32_MAX__ ? 0 : result; 
}

int main(){

}




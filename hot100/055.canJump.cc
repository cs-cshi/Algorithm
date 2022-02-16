/*
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::vector;

// 回溯法：idx 表示当前索引
// 数组很大时会超时
// 错误
void backtrack(vector<int> &nums, int idx, bool &answer)
{
    cout << idx << endl;
    // 当到数组最后一个下标时，说明可以跳跃
    if (idx >= nums.size() - 1)
    { /* condition */
        ;
    }

    if (nums[idx] == 0)
        return;

    cout << idx << endl;
    // 当前跳跃方式无法到达最后一个下标
    // if (idx >= nums.size() || nums[idx] == 0)  // idx > nums.size() 时，也是可以达到
    // if(nums[idx]==0)
    //     return;

    // 当前步骤步数的选择
    /*
    for (int step = 1; step <= nums[idx]; step++)
    {
        // 如果已经判断出可以跳跃，那么不用再遍历了，结束
        if (!answer)
            backtrack(nums, idx + step, answer);
        else
            return;
    }*/
    if (!answer)
        backtrack(nums, idx + nums[idx], answer);
    else
        return;

    if (!answer)
        backtrack(nums, idx + 1, answer);
    else
        return;
}

bool canJump2(vector<int> &nums)
{
    bool answer = false;
    backtrack(nums, 0, answer);
    return answer;
}

bool canJump(vector<int> &nums)
{
    int maxJumpIdx = 0;   // 能够抵达的最远距离。如果能够抵达 maxJumpIdx，那么 < maxJumpIdx 的地方都能抵达
    for (int i = 0; i < nums.size(); i++)
    {
        if (i <= maxJumpIdx)   // i > maxJumpIdx，说明存在值为 0，使不能往后跳了
        {
            maxJumpIdx = max(maxJumpIdx, nums[i] + i);
            if (maxJumpIdx >= nums.size() - 1)
                return true;
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {3, 2, 1, 0, 4};
    bool answer = canJump(nums);
    if (answer)
        cout << "canjump!!!" << endl;
    else
        cout << "cannot~~~" << endl;
    return 0;
}
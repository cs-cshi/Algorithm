/**
 * 55. 跳跃游戏
 * 给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 判断你是否能够到达最后一个下标。
 * 链接：https://leetcode-cn.com/problems/jump-game/
 */

#include <vector>
#include <algorithm>

using std::max;
using std::vector;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        int maxJumpIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maxJumpIndex < i)
                return false;
            maxJumpIndex = max(maxJumpIndex, nums[i] + i);
        }

        return maxJumpIndex >= nums.size() - 1 ? true : false;
    }
};
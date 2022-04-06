/**
 * 45. 跳跃游戏 II
 * 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 * 假设你总是可以到达数组的最后一个位置。
 * 链接：https://leetcode-cn.com/problems/jump-game-ii
 */

#include <vector>
#include <algorithm>

using std::max;
using std::vector;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int result = 0;
        int curDistance = 0;
        int nextDistance = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            nextDistance = max(nextDistance, nums[i] + i);
            if (i == curDistance)
            {
                result++;
                curDistance = nextDistance;
                if (nextDistance >= nums.size() - 1)
                    return result + 1;
            }
        }
        return result;
    }
};
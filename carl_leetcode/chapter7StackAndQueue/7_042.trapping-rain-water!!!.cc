/**
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 链接： https://leetcode-cn.com/problems/trapping-rain-water/
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    /**
     * 单调栈法：去掉情况二，简化代码
     */
    int trap(vector<int> &height)
    {
        // 单调栈，记录索引。遍历 height，当元素小于栈顶时，说明没有出现凹槽，入栈；当大于栈顶时，说明出现了凹槽
        stack<int> stk;
        stk.push(0);
        int sum = 0;
        for (int i = 1; i < height.size(); i++) // 凹槽点遍历
        {
            // 栈不为空，说明左侧有高的墙， height[i] > height[stk.top()]，说明当前元素大于栈顶，栈顶可能是凹槽
            while (!stk.empty() && height[i] > height[stk.top()])
            {
                int mid = stk.top(); // 凹槽索引
                stk.pop();
                if (!stk.empty()) // 左侧存在高的墙
                {
                    int left = stk.top();                               // 左侧的墙的索引
                    int width = i - left - 1;                           //  左右侧墙中间的宽度
                    int h = min(height[i], height[left]) - height[mid]; // 当前槽点水最大深度
                    sum += width * h;
                }
            }
            stk.push(i); // 栈顶不是槽点，当前元素入栈
        }
        return sum;
    }

    /**
     * 单调栈法
     */
    int trap4(vector<int> &height)
    {
        if (height.size() < 3)
            return 0;
        stack<int> stk;
        stk.push(0);
        int sum = 0;
        for (int i = 1; i < height.size(); i++)
        {
            if (height[i] < height[stk.top()]) // 情况一：下一个台阶更低，不是槽点
                stk.push(i);
            else if (height[i] == height[stk.top()]) // 可以不加这种情况，将其合并到情况一。左右两个相等的值同时在栈内，以右为槽的，最大深度会是 0，不会重复计算
            {
                stk.pop();
                stk.push(i);
            }
            else // 下一个台阶变高，出现凹槽
            {
                while (!stk.empty() && height[i] > height[stk.top()])
                {
                    int mid = stk.top(); // 上一阶高度
                    stk.pop();
                    if (!stk.empty())
                    {
                        int width = i - stk.top() - 1; // 注意减一，只求中间的宽度，此时的凹槽计算点是 mid，此刻的 stk.top 是 mid 槽点的左侧边界
                        int h = min(height[stk.top()], height[i]) - height[mid];
                        sum += width * h;
                    }
                }
                stk.push(i);
            }
        }
        return sum;
    }

    /**
     * 动规解法：
     * 题目本质要求问题可以转化为求数组当前索引处左侧和右侧最高柱子问题
     * 可以维护两个动规数组 leftMax,rightMax，左右侧各遍历一次，求出每个索引出处左侧和右侧最高的柱子
     */
    int trap3(vector<int> &height)
    {
        if (height.size() < 3)
            return 0;
        int size = height.size();
        vector<int> leftMax(size);
        vector<int> rightMax(size);
        leftMax[0] = height[0];
        rightMax[size - 1] = height[size - 1];
        for (int i = 1; i < size; i++)
        {
            leftMax[i] = max(leftMax[i - 1], height[i]);
            /*
            if (height[i] > leftMax[i - 1])
                leftMax[i] = height[i];
            else
                leftMax[i] = leftMax[i - 1];
            */
        }

        for (int i = size - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i - 1], height[i]);
            /*
            if (height[i] > rightMax[i + 1])
                rightMax[i] = height[i];
            else
                rightMax[i] = rightMax[i + 1];
            */
        }
        int sum = 0;
        for (int i = 1; i < size - 1; i++)
            sum += min(rightMax[i], leftMax[i]) - height[i];

        return sum;
    }

    /**
     * 暴力解法
     * 对于数组中的每个元素，找出下雨后水能达到的最高位置，等于两边最大高度的较小值减去当前高度的值
     */
    int trap2(vector<int> &height)
    {
        int sum = 0;
        for (int i = 0; i < height.size(); i++)
        {
            if (i == 0 || i == height.size() - 1)
                continue;

            int rHeight = height[i];
            int lHeight = height[i];

            for (int r = i + 1; r < height.size(); r++)
                if (height[r] > rHeight)
                    rHeight = height[r];

            for (int l = i - 1; l >= 0; l--)
                if (height[l] > lHeight)
                    lHeight = height[l];

            int h = min(rHeight, lHeight) - height[i];

            if (h > 0)
                sum += h;
        }
        return sum;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = solution.trap2(nums);
    cout << result << endl;
}
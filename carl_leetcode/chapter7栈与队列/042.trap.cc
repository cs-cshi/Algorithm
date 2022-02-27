/**
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 链接： https://leetcode-cn.com/problems/trapping-rain-water/
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::min;
using std::stack;
using std::vector;

class Solution
{
public:
    /**
     * 单调栈法：去掉情况二，简化代码
     *
     */
    int trap(vector<int> &height)
    {
        stack<int> stk;
        stk.push(0);
        int sum = 0;
        for (int i = 1; i < height.size(); i++)
        {
            while(!stk.empty() && height[i] > height[stk.top()])
            {
                int mid = stk.top();
                stk.pop();
                if(!stk.empty())
                {
                    int width = i - stk.top() - 1;
                    int h = min(height[i], height[stk.top()]) - height[mid];
                    sum += width * h;
                }
            }
            stk.push(i);
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
            if (height[i] < height[stk.top()])      // 情况一：下一个台阶更低，不是槽点
                stk.push(i);
            else if (height[i] == height[stk.top()]) // 可以不加这种情况，将其合并到情况一
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
     * 可以维护两个动规数组 leftMax,rightMax，左右侧各遍历一次，求出每个索引出左侧和右侧最高的柱子
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
            if (height[i] > leftMax[i - 1])
                leftMax[i] = height[i];
            else
                leftMax[i] = leftMax[i - 1];
        }

        for (int i = size - 2; i >= 0; i--)
        {
            if (height[i] > rightMax[i + 1])
                rightMax[i] = height[i];
            else
                rightMax[i] = rightMax[i + 1];
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
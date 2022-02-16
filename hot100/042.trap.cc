/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::stack;
using std::vector;

// 以当前点为中心，水槽的雨水量。
// 实际上要计算的是当前点为中心，两边水槽的最高高度
// 此方法当出现小水槽是就会计算，如果大水槽内含有小水槽，大水槽会被忽视
int expandCenter(vector<int> &height, int idx)
{
    if (idx == 0 || idx >= height.size() - 1)
        return 0;

    int currentTrap = 0;
    int left = idx - 1;
    int right = idx + 1;

    if (height[left] >= height[idx] && height[idx] <= height[right])
    {
        left--;
        right++;

        // 左边界。相邻两个值，当前值大于左侧结点值，并且大于中心结点时，会形成一个水槽边
        while (left >= 0 && height[left] >= height[left + 1])
            left--;

        while (right < height.size() && height[right] >= height[right - 1])
            right++;

        // 水槽边超过边界，仍没有符合水槽边特征的边
        if (height[++left] == height[idx] || height[--right] == height[idx])
            return 0;

        int top = min(height[left], height[right]);

        while (left < right - 1)
        {
            left++;
            currentTrap += top - height[left];
        }

        return currentTrap;
    }
    return 0;
}

// 动态规划法
// 求出数组每个索引 i 处左侧最大值 leftMax[i] 和 右侧最大值rightMax[i]
// 当前索引 i 水深 = min(leftMax[i], rightMax[i]) - height[i]
int trap1(vector<int> &height)
{
    int n = height.size();
    if (n < 3)
        return 0;

    vector<int> leftMax(n); // 存储 i 处左侧最大值 leftMax[i]
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], height[i]);

    vector<int> rightMax(n); // 存储 i 处右侧最大值 leftMax[i]
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], height[i]);

    // 计算总共能接雨水量
    int answer = 0;
    for (int i = 0; i < n; i++)
        answer += min(leftMax[i], rightMax[i]) - height[i];

    return answer;
}

// 栈：存储非递增序列的索引
// 计算水槽以 i 为右界，top 为槽底，横向矩形水域所能容纳的水量
int trap2(vector<int> &height)
{
    int n = height.size();
    if (n < 3)
        return 0;

    stack<int> stk;
    // int top = 0;
    stk.push(0);

    int answer = 0;

    for (int i = 1; i < n; i++)
    {
        while (!stk.empty() && height[i] > height[stk.top()])
        {
            int top = stk.top(); //当前槽底，计算横向延伸水量
            stk.pop();

            if (stk.empty())
                break;

            int left = stk.top();
            int currentWidth = i - left - 1;
            int currentHeight = min(height[left], height[i]) - height[top];
            answer += currentHeight * currentWidth;
        }
        stk.push(i);
    }
    return answer;
}

// 利用到 hot100 11.盛最多水的容器的思想
// 先确定一个高点，leftMax 或 rightMax。（相对最高点和相对次高点）
// 如果需要移动一侧的指针，说明另一侧已经出现了比当前侧更高的高点
// 再移动与最高点另一侧的指针，用当前侧对应的高点 leftMax 或者 rightMax 减去当前指针索引高度，
// 得到的是当前索引最大容水量。
int trap3(vector<int> &height)
{
    int n = height.size();
    if (n < 3)
        return 0;

    int left = 0;
    int right = n - 1;
    int leftMax = height[0];
    int rightMax = height[n - 1];
    int answer = 0;

    // 不需要考虑等于，height[left] 或者 height[right]一定是全局最高点，不可能有水
    while (left < right)
    {
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);

        // 每次移动的都是小的一侧，实际上把大的 Max 已经锁定在了 height[left] 或者 height[right]
        if (height[left] < height[right])
        {
            answer += leftMax - height[left];
            left++;
        }
        else
        {
            answer += rightMax - height[right];
            right--;
        }
    }
    return answer;
}

int main()
{
    vector<int> height = {4, 2, 0, 3, 2, 5};
    int result = trap3(height);
    // int result = expandCenter(height, 2);
    cout << result << endl;
    return 0;
}

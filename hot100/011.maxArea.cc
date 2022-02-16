/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

题目链接：https://leetcode-cn.com/problems/container-with-most-water/
*/

#include <vector>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::max;
using std::vector;

// 暴力解法，超出时间限制
int maxArea(vector<int> &height)
{
    // 2 <= height.size() <= 3 * 104
    // if (height.size() < 2)
    //     return 0;

    int maxVolume = 0;
    // size_t size = height.size();

    for (int i = 0; i < height.size() - 1; i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            maxVolume = max(maxVolume, (height[i] > height[j] ? height[j] * (j - i) : height[i] * (j - i)));
        }
    }
    return maxVolume;
}

// 双指针法
// 左右指针分别指向左右两端，每次移动指针时，移动两者中值小的指针
// 原因：假设左右指针指向的值分别是 x，y，距离为 t，那么最大容量为 min(x,y) * t，若移动较大指针 min(x,y) 的值不会变大，而 t 是递减的，因此容量必然减小
int maxArea2(vector<int> &height)
{
    int left = 0;  // 左指针
    int right = height.size() - 1;  // 右指针
    int maxVolume = 0;  // 记录最大容量

    while (left != right)
    {
        // 更新最大容量
        maxVolume = max(maxVolume,(height[left] > height[right] ? height[right] * (right - left) : height[left] * (right - left))); 
        // 移动指向的值小的指针
        height[left] > height[right] ? --right : ++left;
    }
    return maxVolume;
}

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    // vector<int> height = {1,1};
    // vector<int> height = {4,3,2,1,4};
    // vector<int> height = {1, 2, 1};
    // vector<int> height = {1};
    int result = maxArea2(height);
    cout << result << endl;
    return 0;
}
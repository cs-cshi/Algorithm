/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

1 <= heights.length <=105
0 <= heights[i] <= 104
*/

#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>
#include <stack>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::numeric_limits;
using std::stack;
using std::vector;

// 枚举矩形的底，双重循环，枚举左右边界，并计算当前底中的最小高
int largestRectangleArea(vector<int> &heights)
{
    int ans = 0;
    // 枚举左边界
    for (int left = 0; left < heights.size(); left++)
    {
        int minHeight = __INT_MAX__;
        for (int right = left; right < heights.size(); right++)
        {
            // 确定最小高度
            minHeight = min(minHeight, heights[right]);
            // 计算最大面积
            ans = max(ans, (right - left + 1) * minHeight);
        }
    }
    return ans;
}

// 枚举高，中心扩展法思想
int largestRectangleArea2(vector<int> &heights)
{
    int ans = 0;
    for (int mid = 0; mid < heights.size(); mid++)
    {
        int left = mid;  // 当前高左边界
        int right = mid; // 当前高右边界

        while (left - 1 >= 0 && heights[left - 1] >= heights[left])
            left--;

        while (right + 1 < heights.size() && heights[right + 1] >= heights[right])
            right++;

        ans = max(ans, (right - left + 1) * heights[mid]);
    }
    return ans;
}

// 单调栈法
// 栈依次 push 每一个索引 i，push 前，判断栈顶的元素对应的值是否 >= 当前元素的值，这样保证以当前元素为中心，向左拓展时，栈 top 对应的元素,
// 是距离中心最近的小于当前元素的索引，当栈为空时，说明左侧元素全部大于当前元素
// 同理找到右侧最近的小于当前元素的索引
int largestRectangleArea3(vector<int> &heights)
{
    // 存储左侧最近的小于当前元素的索引
    vector<int> left(heights.size()); // 初始化，默认 size 个 0
    // 存储右侧最近的小于当前元素的索引
    vector<int> right(heights.size());

    int ans = 0;

    stack<int> mono_stack; // 单调栈，栈中值索引对应的元素均小于当前元素

    // 从左至右，确定左界
    for (int i = 0; i < heights.size(); i++)
    {
        // 将栈中索引值对应的值大于当前元素的都弹出，留下小于当前元素对应的索引
        while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
            mono_stack.pop();
        // 确定左界
        left[i] = mono_stack.empty() ? -1 : mono_stack.top();
        mono_stack.push(i);
    }

    mono_stack = stack<int>(); // 重新初始化，清空

    // 从右至左，确定右界
    for (int i = heights.size() - 1; i >= 0; i--)
    {
        while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
            mono_stack.pop();
        right[i] = mono_stack.empty() ? heights.size() : mono_stack.top();
        mono_stack.push(i);
    }

    // 根据每个元素的左右界索引，计算面积
    for (int i = 0; i < heights.size(); i++)
        ans = max(ans, (right[i] - left[i] - 1) * heights[i]);

    return ans;
}

// 单调栈，一次遍历确定左界和右界
/*
  在对位置 i 进行入栈操作时，确定了它的左边界。从直觉上来说，与之对应在对位置 i 进行出栈操作时可以确定它的右边界
  这确实是对的。当位置 i 被弹出栈时，说明此时遍历到的位置 i0​ 的高度小于等于 height[i]，i0 与 i 之间没有其他高度小于等于 height[i] 的柱子。
  这是因为，如果在 i 和 i0 之间还有其它位置的高度小于等于 height[i] 的，那么在遍历到那个位置的时候，i 应该已经被弹出栈了。所以位置 i0 就是位置 i 的右边界。

  我们需要的是「一根柱子的左侧且最近的小于其高度的柱子」，但这里我们求的是小于等于，实际上对答案不会有影响。因为即使值相等的若干柱子，左侧的都计算错误，
  最右侧的一定是可以计算正确的。
*/
int largestRectangleArea4(vector<int> &heights)
{
    int n = heights.size();
    vector<int> left(n,-1);  // 可以不初始化为 -1，每个位置都会 push，一定会赋值
    vector<int> right(n,n);  // 将右侧默认为最右侧，可能存在递增序列，那么就不会存在弹出栈的操作了

    stack<int> mono_stack;

    for (int i = 0; i < n; i++)
    {
        while(!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
        {
            right[mono_stack.top()] = i;    // 确定右界，每个位置不是完全准确，但不影响求最大值
            mono_stack.pop();
        }
        left[i] = mono_stack.empty() ? -1 : mono_stack.top();
        mono_stack.push(i);
    }

    int ans = 0;
    for(int i = 0;i<n;i++)
        ans = max(ans,(right[i]-left[i]-1)*heights[i]);
    
    return ans;
}

int main()
{
    // cout << __INT_MAX__ << endl;
    // cout << numeric_limits<int>::max() << endl;
    vector<int> nums = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea3(nums) << endl;
    return 0;
}
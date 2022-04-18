/**
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
 * 返回 滑动窗口中的最大值 。
 * 链接：https://leetcode-cn.com/problems/sliding-window-maximum
 */

#include <deque>
#include <vector>

using std::deque;
using std::vector;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++) // 先将前 k 个元素加入队列
            que.push(nums[i]);
        result.push_back(que.front()); // 初始化窗口中的最大值
        for (int i = k; i < nums.size(); i++)
        {
            que.pop(nums[i - k]);          // 滑动窗口移动删除左侧元素
            que.push(nums[i]);             // 滑动窗口移动添加右侧新元素
            result.push_back(que.front()); // 当前滑动窗口中的最大值
        }
        return result;
    }

private:
    /**
     * 维护一个可能成为滑动窗口中最大值的元素的队列
     * 注意队列不存储滑动窗口所有的值
     */
    class MyQueue
    {
    public:
        // 从滑动窗口移除头元素
        // 每次弹出元素时，比较当前要弹出的值是否等于队列出口元素的数值，如果相等则弹出
        void pop(int value)
        {
            // 如果头元素不可能是最大值，队列不需删除
            if (!deque.empty() && value == deque.front())
                deque.pop_front();
        }

        // 如果 push 的数值大于入口元素的数值，那么就将入口元素的数值弹出，保证队列中候选最大值
        void push(int value)
        {
            while (!deque.empty() && value > deque.back())
                deque.pop_back();
            deque.push_back(value);
        }
        int front()
        {
            return deque.front();
        }

    private:
        deque<int> deque;
    };
};

int main()
{
    vector<int> nums = {1, 3, 1, 2, 0, 5};
    Solution solution;
    solution.maxSlidingWindow(nums, 3);
}
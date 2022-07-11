/**
 * 76. 最小覆盖子串
 * 难度：hard
 * 给你一个字符串 s 、一个字符串 t。返回 s 中涵盖 t 所有字符的最小子串。
 * 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 * 链接：https://leetcode-cn.com/problems/minimum-window-substring/
 */

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    /**
     * 滑动窗口思想
     * need[c] ：滑动窗口中 c 字符还需要的数量
     * count ：滑动窗口中满足涵盖 t 所有字符还需要的字符数量
     * 关键：结合 need[c] 和 count，维持滑动窗口移动过程中窗口内是否满足涵盖t中所有字符
     */
    string minWindow(string s, string t)
    {
        if (s.size() == 0 || s.size() < t.size())
            return "";

        vector<int> need(128, 0); // 滑动窗口中每个字符需要的数目, ASCII 码 128 个字符
        int count = 0;            // 滑动窗口中需要的字符总数目
        int left = 0;             // 滑动窗口左指针
        int right = 0;            // 滑动窗口右指针
        int start = -1;           // 最小子串起始位置
        int length = INT_MAX;     // 记录最小字串长度

        for (char c : t) // 用于对滑动窗口中还需要的每个字符计数
            need[c]++;

        count = t.size(); // 需要的字符总数，这样对滑动窗口进行check 时不需要再遍历 need 数组来统计是否还有需要的字符

        while (right < s.size()) // 滑动窗口右移遍历
        {
            char c = s[right]; // 当前新加入滑动窗口的字符

            if (need[c] > 0) // 判断是否是需要的字符。对于一直不需要的字符，need 里的值一直会小于等于 0
                count--;
            need[c]--; // 将字符纳入 need，若该字符 < 0，说明是滑动窗口中多出的

            if (count == 0) // 当前滑动窗口出现满足涵盖 t 中所有字符的子串
            {
                while (left < right && need[s[left]] < 0) // 滑动窗口左界元素是多余的，左界移动
                    need[s[left++]]++;                    // 移动左界，由于移出了一个元素，相应的 need 增加

                if (right - left + 1 < length) // 更新最小字串
                {
                    start = left;
                    length = right - left + 1;
                }

                need[s[left++]]++; // 当前滑动窗口在满足涵盖所有字符的条件下无法再左移缩小，窗口强制左移继续遍历寻找最小字串
                count++;           // 左移后窗口内需要的字符增加
            }
            right++; // 窗口右移
        }
        return start == -1 ? "" : s.substr(start, length);
    }
};
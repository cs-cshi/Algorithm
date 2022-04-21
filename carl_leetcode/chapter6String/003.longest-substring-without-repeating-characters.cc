/**
 * 3. 无重复字符的最长子串（hot 100）
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 */

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int arr[128] = {0};            // 滑动窗口内字符是否出现
    int left = 0, right = 0; // 滑动窗口
    int ans = 0;
    if (s.size() == 0)
        return ans;

    while (right < s.size())
    {
        // 窗口右移，更新 arr
        while (right < s.size() && arr[s[right]] == 0)
        {
            arr[s[right]] = 1;
            ans = max(ans, right - left + 1);
            right++;
        }

        // 窗口左移，必须判断 right < s.size()，当滑动窗口移到最右边时，right 会越界
        while (right < s.size() && left < right && s[left] != s[right])
        {
            arr[s[left]] = 0;
            left++;
        }
        arr[s[left]] = 0;
        left++;
    }
    return ans;
}

int main()
{
    string s = "pwwkew";
    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;
}

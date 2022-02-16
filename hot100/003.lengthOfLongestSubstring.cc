/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串的长度。
*/

#include <string>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::string;
using std::unordered_set;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> hashset;
    hashset.insert(s[0]);
    unsigned maxLength = 1;
    unsigned int left = 0; // 用来标识当前无重复字符串的起始位置

    for (unsigned right = 1; right < s.size(); right++)
    {
        if (!hashset.count(s[right])) // hashset 不存在当前字符
        {
            hashset.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        else
        {
            if (hashset.size() == 1) // hashset 中只有一个字符，且和下一个重复
            {
                left++;
                continue;
            }
            hashset.erase(s[left]);
            left++;
            // maxLength = max( maxLength, right-left);
            while (hashset.count(s[right]) > 0) // 重复字符还未删除
            {
                hashset.erase(s[left]); // 去除无重复字符串最左侧字符
                left++;
            }
            hashset.insert(s[right]);
        }
        cout << "right = " << right << "   left=" << left << endl;
        cout << "maxLength = " << maxLength << endl;
    }
    return maxLength;
}

// 滑动窗口
int lengthOfLongestSubstring2(string s)
{
    unordered_set<char> hashset;
    int right = -1; // 相当于滑动窗口右边边界。初始时滑动窗口还不存在，为-1。
    int maxLength = 0;
    for (int left = 0; left < s.size(); left++)
    {
        if (left != 0)
            hashset.erase(s[left - 1]); // 滑动窗口左侧向右移动一个位置
        // 只有当滑动窗口下一个元素不在滑动窗口内时，才加入滑动窗口，并且滑动窗口右侧扩1
        while (right + 1 < s.size() && !hashset.count(s[right + 1]))
        {
            hashset.insert(s[right + 1]);
            right++;
        }
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}

int lengthOfLongestSubstring22(string s)
{
    unordered_set<char> hashset;
    int right = -1;
    int maxLength = 0;
    for (int left = 0; left < s.size(); left++)
    {
        if (left != 0)
            hashset.erase(s[left]);

        while (right + 1 < s.size() && hashset.find(s[right + 1]) == hashset.end())
        {
            right++;
            hashset.insert(s[right]);
        }
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}

int lengthOfLongestSubstring222(string s)
{
    if (s.size() == 0)
        return 0;
    unordered_set<char> hashset;
    unsigned int left = 0;
    unsigned int maxLength = 1;
    hashset.insert(s[0]);

    for (unsigned right = 1; right < s.size(); right++)
    {
        if (hashset.find(s[right]) == hashset.end())
        {
            hashset.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        else
        {
            if (hashset.size() == 1)
            {
                left++;
                continue;
            }
            hashset.erase(s[left++]);
            while (left < right && hashset.find(s[right]) != hashset.end())
                hashset.erase(s[left++]);

            hashset.insert(s[right]);
        }
    }
}

int main()
{
    string s = "pwwkew";
    string s = "bbbbb";
    string s = "";
    lengthOfLongestSubstring(s);
    return 0;
}
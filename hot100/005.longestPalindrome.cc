// 给你一个字符串 s，找到 s 中最长的回文子串。

#include <iostream>
#include <string>
#include <vector>

using std::pair;
using std::string;
using std::vector;
using std::cout;
using std::endl;

// 寻找字符串 s 中的最长子串
// 暴力破解
string longestPalindrome1(string s)
{
    int len = s.length();
    if (len < 2)
        return s;

    int maxLen = 1;
    int begin = 0;

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (j - i + 1 > maxLen && isPalindromic(s.substr(i, j - i + 1)))
            {
                begin = i;
                maxLen = j - i + 1;
            }
        }
    }
    return s.substr(begin, maxLen);
}

// 判断字符串 s 是否是回文子串
bool isPalindromic(string s)
{
    int len = s.length();
    for (unsigned i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
            return false;
    }
    return true;
}

string longestPalindrome2(string s)
{
    int len = s.length();
    if (len < 2)
        return s;

    unsigned begin = 0;
    unsigned maxLen = 1;

    vector<vector<int>> dp(len, vector<int>(len)); // 创造一个二维数组，dp[i][j] 表示 s 从第 i 个到第 j 个是不是回文串

    for (unsigned i = 0; i < len; i++)
        dp[i][i] = 1;

    for (unsigned L = 2; L <= len; L++) // L 表示字串长度
    {
        for (unsigned i = 0; i < len; i++) // i 表示子串起始坐标
        {
            int j = i + L - 1; // j 表示字串结束坐标

            if (j >= len) //  表示当前长度的字串遍历完毕
                break;

            if (s[i] != s[j]) // 子串左右首字母不相等，不是回文串
                dp[i][j] = false;
            else
            {
                if (j - i < 3)
                    dp[i][j] = true; // 子串首尾相等，且长度等于 2 或 3，是回文串
                else
                    dp[i][j] = dp[i + 1][j - 1]; // 如果去除首位字母后的字串是回文串，说明加上首位字母后仍是回文串
            }

            if (dp[i][j] && j - i + 1 > maxLen) // 更新最大回文串
            {
                begin = i;
                maxLen = j - i + 1;
            }
        }
    }
    return s.substr(begin, maxLen);
}

// 使用中心扩展法判断是否是回文子串
string longestPalindrome3(string s)
{
    // 记录最大回文子串的坐标
    int start = 0;
    int end = 0;
    // int left1,left2,right1,right2;

    for (int i = 0; i < s.size(); i++)
    {
        // auto [] c++17 标准
        auto [left1, right1] = expandAroundCenter(s, i, i);     // 中心位于一个点
        auto [left2, right2] = expandAroundCenter(s, i, i + 1); //  中心位于两个点中间

        // 更新最大回文子串索引
        if (right1 - left1 > end - start)
        {
            start = left1;
            end = right1;
        }

        if (right2 - left2 > end - start)
        {
            start = left2;
            end = right2;
        }
    }
    return s.substr(start, end - start + 1);
}

// s 字符串中以 left,right 为中心，扩展判断是否是回文串
pair<int, int> expandAroundCenter(const string &s, int left, int right)
{
    while (left >= 0 && right < s.size() && s[left] == s[right]) // left 是 >= 0
    {
        left--;
        right++;
    }
    return {left + 1, right - 1};
}

int main()
{
    string s = "bb";
    string result = longestPalindrome3(s);
    cout << result << endl;
}
/**
 * 647. 回文子串
 * 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
 * 回文字符串 是正着读和倒过来读一样的字符串。
 * 子字符串 是字符串中的由连续字符组成的一个序列。
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 * 链接：https://leetcode-cn.com/problems/palindromic-substrings
 */

#include <string>
#include <vector>
#include <algorithm>

using std::abs;
using std::string;
using std::vector;

class Solution
{
public:
    int countSubstrings(string s)
    {
        /**
         * 1. dp[i][j]  下标[i,j]是否是回文子串
         * 2. dp[i][j] = false; if s[i] != s[j]
         *    dp[i][j] = true;  i==j
         *             = true;  |i-j| =1
         *             = dp[i-1][j-1]; |i-j|>1
         * 3. 初始化 false
         */
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i; j <= s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (abs(i - j) <= 1)
                    {
                        dp[i][j] = true;
                        result++;
                    }else if(dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
/**
 * 516. 最长回文子序列
 * 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
 * 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
 * 链接：https://leetcode-cn.com/problems/longest-palindromic-subsequence
 */

#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::max;

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        /**
         * 1. dp[i][j]  字符串 s 中区间[i,j]内最长回文子序列长度
         * 2. dp[i][j] = dp[i+1][j-1]+2, s[i]==s[j]
         *             = max(dp[i+1][j],dp[i][j-1])，加入s[i] or s[j]
         */
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++)
            dp[i][i] = 1;
        for (int i = s.size()-1;i>=0;i--)
        {
            for(int j = i;j<s.size();j++)
            {
                if(s[i]==s[j])
                    dp[i][j] = dp[i+1][j-1]+2;
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};
/**
 * 392. 判断子序列
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 * 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 * 进阶：
 * 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
 * 链接：https://leetcode-cn.com/problems/is-subsequence
 */

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    // 双指针法
    bool isSubsequence(string s, string t)
    {
        int indexT = 0;
        int indexS = 0;
        // if (s.size() == 0 || t.size() == 0)
        // return false;

        while (indexS < s.size() && indexT < t.size())
        {
            if (s[indexS] == t[indexT])
                indexS++;
            indexT++;
        }
        if (indexS == s.size())
            return true;
        return false;
    }

    // 递归法，距离编辑的基础
    bool isSubsequence2(string s, string t)
    {
        /**
         * 1. dp[i][j] 以下标 i-1 结尾的字符串 s 与以下标 j-1 结尾的字符串 t 相同子序列长度
         * 2. dp[i][j] = dp[i-1][j-1] + 1, if s[i-1] == t[j-1]
         *             = dp[i][j-1], if s[i-1] != t[j-1]
         * 3. dp[i][j] = 0
         * */
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[s.size()][t.size()] == s.size() ? true : false;
    }
};
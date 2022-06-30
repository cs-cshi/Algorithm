/**
 * 115. 不同的子序列
 * 给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
 * 字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
 * 链接：https://leetcode-cn.com/problems/distinct-subsequences
 */

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        /**
         * 类似于正则匹配 *，匹配 0 次或多次
         * 1. dp[i][j] 以 i-1 结尾的字符串 s 和以 j-1 结尾的字符串 t 中相同子序列个数
         * 2. dp[i][j] = dp[i-1][j-1] + dp[i-1][j], if s[i-1]==t[j-1]
         *    dp[i][j] = dp[i-1][j],                if s[i-1]!=t[j-1]
         * 3. 初始化
         *    dp[i][0] = 1, dp[0][j] = 0, dp[0][0] = 1
         */
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
        for (int i = 0; i <= s.size(); i++)
            dp[i][0] = 1;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];       // 会出现 overflow，需定义为vector<uint64_t>类型
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};
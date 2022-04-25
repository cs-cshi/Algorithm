/**
 * 10. 正则表达式匹配
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 *     '.' 匹配任意单个字符
 *     '*' 匹配零个或多个前面的那一个元素
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 * 链接：https://leetcode-cn.com/problems/regular-expression-matching
 */

#include <string>
#include <vector>
#include <iostream>s

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {

        int len1 = s.size();
        int len2 = p.size();
        // dp[i][j]：s 的前 i 个字符与 p 的前 j 的字符是否匹配
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;

        /*
        if p[j] != '*', match(s[i],p[j]), dp[i][j] = d[i-1][j-1]
                       !match(s[i],p[j]), dp[i][j] = false;
        当 p[j] 为 * 时，如果 s[i],p[j-1] 不能匹配，那只能是 * 匹配 0 次的结果 dp[i][j-2]
                                           能匹配，可能是 0 次也可能是多次，如果是多次，那么相当于与 s[i] 去掉，用s[i-1]来匹配，即 dp[i-1][j]
        if p[j] == '*', match(s[i],p[j-1]), dp[i][j] = dp[i][j-2] || dp[i-1][j]
                       !match(s[i],p[j-1]), dp[i][j] = dp[i][j-2]
        */

        // i, j 不是索引
        auto match = [&](int i, int j)
        {
            if (i == 0)
                return false;

            if (p[j - 1] == '.')
                return true;

            return s[i - 1] == p[j - 1];
        };

        // i = 0, j!=0 时，也可能匹配成功，如 p = "a*"
        for (int i = 0; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (p[j - 1] != '*')
                {
                    if (match(i, j))
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = false;
                }
                else
                {
                    if (match(i, j - 1))
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    else
                        dp[i][j] = dp[i][j - 2];
                }
            }
            for (int i = 0; i <= len1; i++)
            {
                for (int j = 0; j <= len2; j++)
                    cout << dp[i][j] << " ";
                cout << endl;
            }
        }

        return dp[len1][len2];
    }
};
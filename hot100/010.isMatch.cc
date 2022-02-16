/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
*/
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

bool isMatch(string s, string p)
{
    
    /*
        判断 s 的第 i 个和 p 的第 j 个字符是否匹配。匹配的情况：
        1. 两个字符相等
        2. 或者 p 对应的字符是 '.'
    */
    auto matchs = [&](int i, int j)
    {
        if (i == 0)
            return false;

        if (p[j - 1] == '.')
            return true;

        return s[i - 1] == p[j - 1];
    };

    int m = s.size();
    int n = p.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1)); 
    dp[0][0] = true;    // 第一行第一列，除了[0][0] 是 true 外都是 false

    for (int i = 0; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 2];
                if (matchs(i, j - 1))
                    dp[i][j] |= dp[i - 1][j];   // 或，有一个为 true 就是 true
            }
            else
            {
                if (matchs(i, j))
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = false;
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string s("aaa");
    string p("ab*a*c*a");
    bool ret = isMatch(s, p);
    if (ret)
        cout << "yeah~~~" << endl;
    return 0;
}
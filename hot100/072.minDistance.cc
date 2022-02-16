/*
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
*/

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using std::min;
using std::string;
using std::vector;

/*
我们可以对任意一个单词进行三种操作：
    插入一个字符； 
    删除一个字符；
    替换一个字符。

对于单词 A 和 单词 B，可以有6中操作，本质不同的操作实际上只有三种：
    在单词 A 中插入一个字符；
    在单词 B 中插入一个字符；
    修改单词 A 的一个字符。

用D[i][j] 表示 A 的前 i 个字母和 B 的前 j 个字母之间的编辑距离。当我们获得 D[i][j-1]，D[i-1][j] 和 D[i-1][j-1] 的值之后就可以计算出 D[i][j]。
    D[i][j-1] 为 A 的前 i 个字符和 B 的前 j - 1 个字符编辑距离的子问题。即对于 B 的第 j 个字符，我们在 A 的末尾添加了一个相同的字符，那么 D[i][j] 最小可以为 D[i][j-1] + 1；
    D[i-1][j] 为 A 的前 i - 1 个字符和 B 的前 j 个字符编辑距离的子问题。即对于 A 的第 i 个字符，我们在 B 的末尾添加了一个相同的字符，那么 D[i][j] 最小可以为 D[i-1][j] + 1；
    D[i-1][j-1] 为 A 前 i - 1 个字符和 B 的前 j - 1 个字符编辑距离的子问题。即对于 B 的第 j 个字符，我们修改 A 的第 i 个字符使它们相同，那么 D[i][j] 最小可以为 D[i-1][j-1] + 1。
  特别地，如果 A 的第 i 个字符和 B 的第 j 个字符原本就相同，那么我们实际上不需要进行修改操作。在这种情况下，D[i][j] 最小可以为 D[i-1][j-1]。
*/

// 动规
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    // 其中一个字符串为空
    if (!n || !m)
        return 0;

    // 动规数组
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // 初始化边界
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = i;

    for (int j = 0; j < m + 1; j++)
        dp[0][j] = j;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            // int down = dp[i-1][j];
            // int left = dp[i][j-1];
            // int leftDown = dp[i-1][j-1];
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
            else
                dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
        }
    }
    return dp[n][m];
}

int main()
{
    string word1("horse");
    string word2("ros");
    int ans = minDistance(word1, word2);
    std::cout << ans << std::endl;
    return 0;
}
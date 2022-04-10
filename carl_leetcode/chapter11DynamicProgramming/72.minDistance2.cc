/**
 * 72. 编辑距离
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
 * 你可以对一个单词进行如下三种操作：
 *     插入一个字符
 *     删除一个字符
 *     替换一个字符
 * 链接：https://leetcode-cn.com/problems/edit-distance
 */

#include <vector>
#include <algorithm>
#include <string>

using std::min;
using std::string;
using std::vector;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        /**
         * 1. dp[i][j] 以 i,j 结尾的字符串转换最少需操作的步数
         * 2. dp[i][j] = dp[i-1][j-1]    ==
         *             = min(min(dp[i-1][j]+1,dp[i][j-1]+1,)dp[i-1][j-1]+1) !=
         * 3. 初始化 dp[i][0] = i, dp[0][j] = j
         */
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 0; i <= word1.size(); i++)
            dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++)
            dp[0][j] = j;
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1);
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
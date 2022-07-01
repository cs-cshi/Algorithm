/**
 * 583. 两个字符串的删除操作
 * 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。
 * 每步 可以删除任意一个字符串中的一个字符。
 * 链接：https://leetcode-cn.com/problems/delete-operation-for-two-strings/
 */

#include <string>
#include <vector>
#include <algorithm>

using std::min;
using std::string;
using std::vector;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        /**
         * dp[i][j] 以 i-1 结尾的字符串 word1 与 j-1 结尾的字符串 word2，要想两个字符相同，所需要删除元素的最少次数
         * dp[i][j] = dp[i-1][j-1],if word[i-1]==word[j-1]
         *          = min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+2 ,if word[i-1]!=word[j-1]
         * dp[i][0] = i,dp[0][j] = j
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
                    dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1] + 2);
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
/**
 * 139. 单词拆分
 * 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
 * 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
 * 链接：https://leetcode-cn.com/problems/word-break
 */

#include <string>
#include <vector>
#include <unordered_set>

using std::string;
using std::unordered_set;
using std::vector;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return backtracking(s, wordSet, 0);
    }

    bool backtracking(const string &s, const unordered_set<string> &wordSet, int startIndex)
    {
        if (startIndex >= s.size())
            return true;

        for (int i = startIndex; i < s.size(); i++)
        {
            string word = s.substr(startIndex, i - startIndex + 1);
            if (wordSet.find(word) != wordSet.end())
                if (backtracking(s, wordSet, i + 1))
                    return true;
        }
        return false;
    }

    bool dynamicProgramming(string &s, vector<string> &wordDict)
    {
        // dp[i] 字符串 s 前 i 个字符可以拆分为一个或多个字典中的单词
        // dp[j] = dp[i] && check(s[i,j-i+1])
        // dp[0] true
        // 顺序：从前往后

        vector<bool> dp(s.length() + 1);
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        for (int i = 0; i < s.size(); i++)
            for (int j = 1; i <= i; j++)
                if (wordSet.find(s.substr(j, j - i)) != wordSet.end() && dp[j])
                    dp[j] = true;
        return dp[s.size()];
    }
};
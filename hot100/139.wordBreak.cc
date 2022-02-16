/*
给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::string;
using std::unordered_set;
using std::vector;

/*
动规方法：
dp[i] = dp[j] && check(s.substr(j,i-j));
以 j 为界，判断 j 之前的是否能拆分，再判断 j~i 这一段子串是否是单词
*/
bool wordBreak2(string s, vector<string> &wordDict)
{
    unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1);
    dp[0] = true; // 作为最前面第一个单词的旗标
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end())
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

/*
    动规方法：
    递归关系：dp[i] = dp[j] && check(s.substr(j,i-j));
    以 j 为界，判断 j 之前的是否能拆分，再判断 j~i 这一段子串是否是单词
    剪枝：只判断 j-i < word 最大长度的场景
*/
bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1);
    int max_substr_length = 0;
    for (const string &word : wordDict) // 用于剪枝
        max_substr_length = max(max_substr_length, int(word.length()));

    dp[0] = true; // 作为最前面第一个单词的旗标
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = i; j >= 0 && j >= i - max_substr_length; j--)
        {
            if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end())
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

int main()
{
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    if (wordBreak(s, wordDict))
    {
        cout << "yeah~" << endl;
    }
}
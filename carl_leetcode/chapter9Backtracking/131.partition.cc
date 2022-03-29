/**
 * 131. 分割回文串
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 * 回文串 是正着读和反着读都一样的字符串。
 * https://leetcode-cn.com/problems/palindrome-partitioning/
 */

#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> path;
        if (s.size() > 0)
            backtracking(result, path, 0, s);
        return result;
    }

    // 把整个字符串中构成回文子串的字符串当成之前回溯问题中一个数字
    void backtracking(vector<vector<string>> &result, vector<string> &path, int startIndex, string &s)
    {
        if (startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); i++)
        {
            if (isPalindrome(s, startIndex, i))
            {
                string subStr = s.substr(startIndex, i - startIndex + 1);
                path.push_back(subStr);
            }
            else
                continue;

            backtracking(result, path, i + 1, s);
            path.pop_back();
        }
    }

    bool isPalindrome(string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};
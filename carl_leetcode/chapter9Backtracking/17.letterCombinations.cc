/**
 * 17. 电话号码的字母组合
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
 */

#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        string path;
        if (digits.size() != 0)
            backtracking(result, path, digits, 0);
        return result;
    }

    void backtracking(vector<string> &result, string &path, string &digits, int index)
    {
        if (index == digits.size())
        {
            result.push_back(path);
            return;
        }

        int digit = digits[index] - '0';
        string letter = letterMap[digit];
        for (int i = 0; i < letter.size(); i++)
        {
            path.push_back(letter[i]);
            backtracking(result, path, digits, index + 1);
            path.pop_back();
        }
    }

    void backtracking2(vector<string> &ans, string &path, int startIndex, const string &digits)
    {
        // cout << path << endl;
        if (path.size() == digits.size())
        {
            ans.push_back(path);
            return;
        }

        int index = digits[startIndex] - '0';
        // cout << index << endl;
        for (int i = 0; i < letterMap[index].size(); i++) // 横向从 0 开始
        {
            path.push_back(letterMap[index][i]);
            backtracking2(ans, path, startIndex + 1, digits); // 纵向进入下一个串
            path.pop_back();
        }
    }

private:
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };
};
/*
17. 电话号码的字母组合

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> letterCombinations1(string digits)
{
    vector<string> answer;
    vector<string> numPad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if (digits.empty())
        return answer;
    letterCombinationsDFS(digits, answer, numPad);
    return answer;
}

void letterCombinationsDFS(string digits, vector<string> &answer, const vector<string> &numPad)
{
    if (digits.empty())
    {
        answer.push_back("");
        return;
    }
    int digit = digits[0] - '0';   // 将 digits 第一个数字字符转为数字
    digits.erase(0, 1);            // 删除第一个数字字符
    vector<string> partialAnswers; // 对于最后一次递归时， partialAnswers 是空串
    letterCombinationsDFS(digits, partialAnswers, numPad);
    for (auto currentChar : numPad[digit])
    {
        for (auto partialAnswerString : partialAnswers)
            answer.push_back(currentChar + partialAnswerString);
    }
}

int main()
{
    string digits = "23";
    vector<string> ret = letterCombinations1(digits);
    for (auto iter : ret)
    {
        cout << iter << endl;
    }
}
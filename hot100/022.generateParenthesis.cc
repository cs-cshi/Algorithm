/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
*/

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// 判断括号组合是否有效
bool isValid(const string &str)
{
    int balance = 0; // 记录当前需要平衡的左括号数
    for (char c : str)
    {
        if (c == '(')
            ++balance;
        else
            --balance;

        if (balance < 0)
            return false; // 失衡，当前组合无效
    }
    return balance == 0; // 是否完全匹配
}

// 生成所有的括号组合，先不管()是否会匹配
void genarateParenthesisAll(string &current, int n, vector<string> &result)
{
    // 递归终止条件，已生成 n 对括号
    if (current.size() == n)
    {
        if (isValid(current))
            result.push_back(current);
        return;
    }

    // 下一个括号是 (
    current += '(';
    genarateParenthesisAll(current, n, result);
    current.pop_back();

    // 下一个括号是 )
    current += ')';
    genarateParenthesisAll(current, n, result);
    current.pop_back();
}

// 对 1 的改进，以成对的方式，跟踪 ( 和 ) 的数目，控制最后生成了 n 个 ( 和 n 个 )
// open：当前括号组合中已有 ( 的个数
// close：当前括号组合中已有 ) 的个数
// n：生成目标括号组合对数
void genarateParenthesisAll2(string &current, int n, int open, int close, vector<string> &result)
{
    // 递归退出条件，当前生成组合已有 n 对
    if (current.size() == n * 2)
    {
        result.push_back(current);
        return;
    }

    if (open < n)
    {
        current += '(';
        genarateParenthesisAll2(current, n, open + 1, close, result);
        current.pop_back();
    }

    if (close < open)
    {
        current += ')';
        genarateParenthesisAll2(current, n, open, close + 1, result);
        current.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> result;
    string current;
    // genarateParenthesisAll(current, n * 2, result);
    genarateParenthesisAll2(current, n, 0, 0, result);
    return result;
}

int main()
{
    vector<string> result = generateParenthesis(3);

    for (auto item : result)
        cout << "\" " << item << " \"";
    cout << endl;
    return 0;
}
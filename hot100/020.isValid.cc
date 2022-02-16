// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

bool isValid(string s)
{
    if (s.size() < 2) // 特例：s 为空或只有一个字符
        return false;

    vector<char> stack; // 用 vector 模拟栈
    int top = -1;       // 模拟栈顶
    bool flag = true;   // 标签

    for (auto c : s)
    {
        if (c == '(' || c == '[' || c == '{') // 左括号，入栈
        {
            stack.push_back(c);
            top++;
        }
        else // 右括号，与栈顶匹配
        {
            if (top == -1) // 栈为空，且待匹配字符为右括号
                return false;

            switch (c)
            {
            case ')':
                stack[top] == '(' ? flag = true : flag = false;
                stack.pop_back();
                top--;
                break;
            case '}':
                stack[top] == '{' ? flag = true : flag = false;
                stack.pop_back();
                top--;
                break;
            case ']':
                stack[top] == '[' ? flag = true : flag = false;
                stack.pop_back();
                top--;
                break;
            default: // 不是这几个括号
                return false;
            }

            if (!flag) // 当前栈顶不匹配
                return false;
        }
    }

    if (top != -1)
        return false;
    return true;
}

int main()
{
    string s = "aab";
    string s = "){";
    cout << isValid(s) << endl;
}
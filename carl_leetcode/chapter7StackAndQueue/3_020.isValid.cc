/**
 * 20. 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 有效字符串需满足：
 *      左括号必须用相同类型的右括号闭合。
 *      左括号必须以正确的顺序闭合。
 *
 * 链接：https://leetcode-cn.com/problems/valid-parentheses
 */

#include <string>
#include <stack>
#include <iostream>

using std::cout;
using std::endl;
using std::stack;
using std::string;

class Solution
{
public:
    bool isValid2(string s)
    {
        stack<char> stack;
        bool flag = true;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            switch (c)
            {
            case '(':
                stack.emplace(c);
                break;
            case '{':
                stack.emplace(c);
                break;
            case '[':
                stack.emplace(c);
                break;
            case ')':
                if (!stack.empty() && stack.top() == '(')
                    stack.pop();
                else
                    flag = false;
                break;
            case '}':
                if (!stack.empty() && stack.top() == '{}')
                    stack.pop();
                else
                    flag = false;
                break;
            case ']':
                if (!stack.empty() && stack.top() == '[')
                    stack.pop();
                else
                    flag = false;
                break;
            default:
                break;
            }
            if (!flag)
                return false;
        }
        if (stack.empty())
            return true;
    }

    /**
     * 1. 栈存储正确匹配的右括号
     * 2. 遍历 s 时遇到右括号，如果与栈顶不匹配（包含栈空），说明之前匹配出错
     * 3. 如果能匹配上，说明当前左右括号正确匹配，弹出
     * */
    bool isValid(string s)
    {
        stack<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                stack.emplace(')');
            else if (s[i] == '[')
                stack.emplace(']');
            else if (s[i] == '{')
                stack.emplace('}');
            else if (stack.empty() || stack.top() != s[i])
                return false;
            else
                stack.pop();
        }
        return stack.empty();
    }

    bool isValid2(string s)
    {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                stk.push(')');
            else if(s[i] == '[')
                stk.push(']');
            else if(s[i]== '{')
                stk.push('}');
            else if(stk.empty() || stk.top() != s['i'])
                return false;
            else
                stk.pop();
        }
        return true;
    }
};

int main()
{
    Solution solution;
    bool result = solution.isValid("()[]{}");
    cout << result << endl;
}
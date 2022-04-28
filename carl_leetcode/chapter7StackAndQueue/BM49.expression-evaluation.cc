/**
 * BM49 表达式求值
 * 请写一个整数计算器，支持加减乘三种运算和括号。
 * 数据范围：0≤∣s∣≤100，保证计算结果始终在整型范围内
 * 要求：空间复杂度： O(n)O(n)，时间复杂度 O(n)O(n)
 */

#include <string>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    int solve(string s)
    {
        // write code here
        stack<char> stk1;
        stack<int> stk2;
        queue<string> que;

        int num = 0;
        bool flag = false;
        // 中序转后序
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + s[i] - '0';
                if (i == s.size() - 1)
                    que.push(to_string(num));
                flag = true;
            }
            else
            {
                // if (s[i] != '(' && s[i] != ')')
                if (s[i] != '(' && flag)
                {
                    que.push(to_string(num));
                    flag = false;
                }

                num = 0;

                // 直接入栈，运算符优先级高于栈顶运算符
                if (stk1.empty() || s[i] == '(' || ((s[i] == '*' || s[i] == '/') && (stk1.top() == '+' || stk1.top() == '-')))
                    stk1.push(s[i]);
                else
                {                    // 弹出后入栈，运算符优先级相等或低于栈顶
                    if (s[i] == ')') // 封闭括号，弹出整个括号内的运算符
                    {
                        while (stk1.top() != '(')
                        {
                            string s(1, stk1.top());
                            que.push(s);
                            // que.push(to_string(stk1.top()));
                            stk1.pop();
                        }
                        stk1.pop(); // 弹出 '('
                    }
                    else
                    {
                        if (s[i] == '*' || s[i] == '/') // 为 *、/ 运算符
                        {
                            while (!stk1.empty() && (stk1.top() == '*' || stk1.top() == '/'))
                            {
                                string s(1, stk1.top());
                                que.push(s);
                                // que.push(to_string(stk1.top()));
                                stk1.pop();
                            }
                        }
                        else
                        {
                            // +、- 运算符，弹出直至空或 (
                            while (!stk1.empty() && stk1.top() != '(')
                            {
                                string s(1, stk1.top());
                                que.push(s);
                                stk1.pop();
                            }
                        }
                        stk1.push(s[i]);
                    }
                }
            }
        }

        while (!stk1.empty())
        {
            string s(1, stk1.top());
            que.push(s);
            stk1.pop();
        }

        // 后序表达式求值
        int ans = 0, num1 = 0, num2 = 0;
        while (!que.empty())
        {
            string tmp = que.front();
            que.pop();
            if (tmp.size() > 1)
            {
                stk2.push(stoi(tmp));
                continue;
            }
            else if (tmp[0] >= '0' && tmp[0] <= '9')
                stk2.push(stoi(tmp));
            else
            {
                num2 = stk2.top();
                stk2.pop();
                num1 = stk2.top();
                stk2.pop();
                if (tmp[0] == '+')
                    stk2.push(num1 + num2);
                else if (tmp[0] == '-')
                    stk2.push(num1 - num2);
                else if (tmp[0] == '*')
                    stk2.push(num1 * num2);
                else
                    stk2.push(num1 * num2);
            }
        }
        cout << stk2.top();
        return stk2.top();
    }
};

int main()
{
    Solution solution;
    string s = "100+100";
    solution.solve(s);
}

/*

a + b * c + (d * e + f)*g


+*

abc*+de*f+g*+
123*+45*6+7*+




*/
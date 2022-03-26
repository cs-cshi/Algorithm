/**
 * 根据 逆波兰表示法，求表达式的值。
 * 有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 * 注意 两个整数之间的除法只保留整数部分。
 * 可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 * 链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation
 */
#include <vector>
#include <string>
#include <stack>
#include <iostream>

using std::stack;
using std::string;
using std::vector;
using std::stoi;
using std::cout;
using std::endl;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stack;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                if (stack.size() < 2)
                    return -1;
                int nums1 = int(stack.top());
                stack.pop();
                int nums2 = int(stack.top());
                stack.pop();
                if (tokens[i] == "+")
                    stack.emplace(nums2 + nums1);
                else if (tokens[i] == "-")
                    stack.emplace(nums2 - nums1);
                else if (tokens[i] == "*")
                    stack.emplace(nums2 * nums1);
                else
                    stack.emplace(nums2 / nums1);
            }
            else
                stack.emplace(stoi(tokens[i]));
        }
        return int(stack.top());
    }
};

int main()
{
    Solution solution;
    // vector<string> tokens = {"2","1","+","3","*"};
    vector<string> tokens = {"4","13","5","/","+"};
    int result = solution.evalRPN(tokens);
    cout << result << endl;
}
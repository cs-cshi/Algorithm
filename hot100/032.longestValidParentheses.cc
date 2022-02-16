/*
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
*/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::stack;
using std::string;
using std::vector;

// 使用栈来实现括号匹配
int longestValidParentheses(string s)
{
    if (s.empty())
        return 0;

    int longest = 0;

    stack<int> stack;
    stack.push(-1); // 栈底标识

    // 压进栈的是索引，不是字符 c，这样方便计算有多少个括号，当前序号 i - 栈顶元素对顶的序号 = 当前括号成功匹配时具体的括号数目
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') // 只压 ( 进栈
        {
            stack.push(i);
        }
        else
        {
            // 当前 ) 括号匹配成功。栈里全是 (
            stack.pop();
            if (stack.empty()) // 若 -1 也出栈，说明此前序列括号已经无法完成匹配，重新计算括号成功匹配序列起始位置
                stack.push(i);
            else
                longest = max(longest, i - stack.top());
        }
    }
    return longest;
}

// 使用动态规划
int longestValidParentheses2(string s)
{
    if (s.size() < 2)
        return 0;

    int longest = 0;
    // dp[i] 记录以 dp[i] 结尾的最长括号匹配长度
    vector<int> dp(s.size(), 0);

    for (int i = 1; i < s.size(); i++)
    {
        // 第一种情况，以 ()结尾
        if (s[i] == ')' && s[i - 1] == '(')
            dp[i] = (i > 2 ? dp[i - 2] : 0) + 2;
        // 第二种情况，以 )) 结尾，此时要判定 *()) 前的 * 是否是 (，如果不是说明当前的 ) 无法匹配，直接不用计算，为 0
        else if (s[i] == ')' && s[i - dp[i - 1] - 1] == '(')
            dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;

        longest = max(longest, dp[i]);
    }
    return longest;
}

// 使用计算左右括号数来匹配
// 从左往右遍历，若右括号 ) 大于左括号 ( 数目，说明当前已不匹配，从0重新开始计数，注意此时是无法计算出 ( 括号不匹配的情况的
// 再从右往左遍历，计算左括号数目大于右括号数目情况。 ( 左括号不匹配的情况。此时无法计算 ) 。
int longestValidParentheses3(string s)
{
    int longest = 0;
    int left = 0;  // 左括号 ( 数目
    int right = 0; // 右括号 ) 数目

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
            left++;
        else
            right++;

        if (left == right) // 左右括号数目相等，匹配成功，记录最大值，此时应该以右括号数目为基准计算总数
            longest = max(longest, right * 2);
        else if (right > left) // (())) 情况，当前不匹配，重新对左右括号计数，左括号多的情况是没办法通过计数得出来是否不匹配的
            left = right = 0;
    }

    left = right = 0;

    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] == '(')
            left++;
        else
            right++;

        if (left == right)
            longest = max(longest, left * 2);
        else if (left > right) // 左括号 ( 比右括号 ) 多的情况。从右往左遍历，此时可以判断出左括号是否能匹配上
            left = right = 0;
    }

    return longest;
}

int main()
{
    string str = ")(()))";
    int result = longestValidParentheses(str);
    cout << result << endl;
    return 0;
}
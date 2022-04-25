/**
 * BM43 包含min函数的栈
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的 min 函数，输入操作时保证 pop、top 和 min 函数操作时，栈中一定有元素。
 * 此栈包含的方法有：
 *     push(value):将value压入栈中
 *     pop():弹出栈顶元素
 *     top():获取栈顶元素
 *     min():获取栈中最小元素
 */

#include <stack>

using namespace std;

class Solution
{
public:
    void push(int value)
    {
        // 不空时，<= 入栈，注意相等也要入栈
        if (!stk2.empty())
        {
            if (value <= stk2.top())
                stk2.push(value);
        }
        else
            stk2.push(value);
        stk1.push(value);
    }

    void pop()
    {
        if (stk1.top() == stk2.top())
            stk2.pop();
        stk1.pop();
    }

    int top()
    {
        return stk1.top();
    }

    int min()
    {
        return stk2.top();
    }

private:
    stack<int> stk1;
    stack<int> stk2; // 记录最小值
};
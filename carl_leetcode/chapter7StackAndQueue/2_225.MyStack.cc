#include <queue>
#include <iostream>

using std::cout;
using std::endl;
using std::queue;

/**
 * 使用两个单向队列模拟栈
 */
class MyStack
{
public:
    MyStack()
    {
        queue1 = new queue<int>();
        queue2 = new queue<int>();
    }

    void push(int x)
    {
        queue1->push(x);
    }

    int pop()
    {
        int size = queue1->size();
        size--;
        while (size--)
        {
            queue2->push(queue1->front());
            queue1->pop();
        }
        int result = queue1->front();
        queue1->pop();
        // queue1 = queue2;  // queue1、queue2 是指针，如果直接赋值，那么原本的 queue1 将不复存在，出现内存泄露
        while (!queue2->empty())
        {
            queue1->push(queue2->front());
            queue2->pop();
        }
        return result;
    }

    int top()
    {
        int result = this->pop();
        queue1->push(result);
        return result;
        // return queue1->back();
    }

    bool empty()
    {
        return queue1->empty();
    }

private:
    queue<int> *queue1;
    queue<int> *queue2;
};

/**
 * 使用一个单向队列模拟战
 */
class MyStack2
{
public:
    MyStack2()
    {
        que = new queue<int>();
    }

    ~MyStack2()
    {
        delete que;
    }

    void push(int val)
    {
        que->push(val);
    }

    int top()
    {
        int result = this->pop();
        que->push(result);
        return result;
    }

    int pop()
    {
        int count = que->size();
        count--;
        while (count--)
        {
            que->push(que->front());
            que->pop();
        }
        int result = que->front();
        que->pop();
        return result;
    }

    bool empty() const
    {
        return que->empty();
    }

private:
    queue<int> *que;
};

int main()
{
    MyStack2 *mystack = new MyStack2();
    mystack->push(1);
    mystack->push(2);
    int top1 = mystack->top();
    int pop1 = mystack->pop();
    bool result = mystack->empty();
    cout << "top1 " << top1 << endl;
    cout << "pop1 " << pop1 << endl;
    cout << "result " << result << endl;
}

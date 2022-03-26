#include <queue>
#include <iostream>

using std::cout;
using std::endl;
using std::queue;

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

int main()
{
    MyStack *mystack = new MyStack();
    mystack->push(1);
    mystack->push(2);
    int top1 = mystack->top();
    int pop1 = mystack->pop();
    bool result = mystack->empty();
    cout << "top1 " << top1 << endl;
    cout << "pop1 " << pop1 << endl;
    cout << "result " << result << endl;
}

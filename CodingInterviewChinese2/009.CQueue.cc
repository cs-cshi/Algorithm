#include <stack>

using std::stack;

class CQueue
{
public:
    CQueue()
    {
        while (!stackIn.empty())
            stackIn.pop();

        while (!stackOut.empty())
            stackOut.pop();
    }

    void appendTail(int value)
    {
        stackIn.push(value);
    }

    int deleteHead()
    {
        if (stackOut.empty())
        {
            if (stackIn.empty())
                return -1;
            
            while(!stackIn.empty())
            {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }

        
        int deleteValue = stackOut.top();
        stackOut.pop();
        return deleteValue;
        
    }
private:
    stack<int> stackIn, stackOut;
};

int main()
{
    return 0;
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
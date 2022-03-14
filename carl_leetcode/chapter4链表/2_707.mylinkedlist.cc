#include <iostream>

using std::cout;
using std::endl;

class MyLinkedList
{
public:
    // 链表节点结构体
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode() : val(0), next(nullptr) {}
        LinkedNode(int val) : val(val), next(nullptr) {}
    };

    // 构造函数初始化
    MyLinkedList()
    {
        _size = 0;
        _dummyHead = new LinkedNode(0); // 虚头结点
    }

    // 在链表尾部添加节点
    void addAtTail(int val)
    {
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *cur = _dummyHead;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // 在链表头部添加节点
    void addAtHead(int val)
    {
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    // index 从 0 开始，头结点是第 0 个节点
    int get(int index)
    {
        if (index > (_size - 1) || index < 0)
            return -1;
        LinkedNode *cur = _dummyHead->next;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    // 在第 index 个节点之前插入一个新节点
    // 如果 index 为 0，新插入节点为头结点
    void addAtIndex(int index, int val)
    {
        if (index > _size)
            return;

        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *cur = _dummyHead;
        while (index--)
            cur = cur->next;
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    // 删除第 index 个节点，index 从 0 开始
    void deleteAtIndex(int index)
    {
        if (index > (_size - 1) || index < 0)
            return;

        LinkedNode *cur = _dummyHead;
        while (index--)
            cur = cur->next;
        LinkedNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }

    // 打印链表
    void printLinkedList()
    {
        LinkedNode *cur = _dummyHead;
        while (cur->next != nullptr)
        {
            cout << cur->next->val << "  ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    int _size;
    LinkedNode *_dummyHead;
};

int main()
{
    MyLinkedList *myLinkedList = new MyLinkedList();
    myLinkedList->addAtTail(3);
    myLinkedList->addAtHead(1);
    myLinkedList->addAtHead(2);
    myLinkedList->printLinkedList();
    myLinkedList->addAtIndex(1, 4);
    myLinkedList->printLinkedList();
    cout << myLinkedList->get(1) << endl;
    myLinkedList->deleteAtIndex(2);
    cout << myLinkedList->get(2) << endl;
}
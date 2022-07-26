/**
 * 从链表中删除指定值的节点
 * ACM 模式，自定义构建链表
 */
#include <iostream>

using namespace std;

struct LinkedNode
{
    int val;
    LinkedNode *next;
    LinkedNode(int val) : val(val), next(nullptr) {}
    LinkedNode(int val, LinkedNode *next) : val(val), next(next) {}
};

// 在 dummyHead 链表的 pre 后插入节点 val
void insertNode(LinkedNode *dummyHead, int pre, int val)
{
    LinkedNode *preNode = dummyHead;
    LinkedNode *nextNode = nullptr;
    while (preNode->next && preNode->next->val != pre)
        preNode = preNode->next;
    preNode = preNode->next;
    nextNode = preNode->next;
    preNode->next = new LinkedNode(val);
    preNode->next->next = nextNode;
    //     return true;
}

void deleteNode(LinkedNode *dummyHead, int val)
{
    LinkedNode *preNode = dummyHead;
    LinkedNode *nextNode = nullptr;
    while (preNode->next && preNode->next->val != val)
    {
        preNode = preNode->next;
    }
    LinkedNode *tempNode = preNode->next;
    preNode->next = preNode->next->next;
    delete tempNode;
    tempNode = nullptr;
}

int main()
{
    int count;
    cin >> count;
    int num1;
    int num2;
    cin >> num1;
    LinkedNode *dummyHead = new LinkedNode(0); // 虚头节点
    dummyHead->next = new LinkedNode(num1);    // 头节点
    LinkedNode *tempNode = dummyHead;
    while (--count)
    {
        cin >> num1 >> num2;
        insertNode(dummyHead, num2, num1); // 构建链表
    }
    int deleteNum;
    cin >> deleteNum;
    //     cout << deleteNum << endl;

    deleteNode(dummyHead, deleteNum);

    while (tempNode->next)
    {
        cout << tempNode->next->val << " ";
        tempNode = tempNode->next;
    }
    //     if(tempNode != nullptr)
    //         cout << tempNode;
    return 0;
}
#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::stack;
using std::vector;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) : val(val) {}
};

// 使用栈实现
vector<int> reversePrint(ListNode *head)
{
    stack<ListNode *> nodes;
    vector<int> res;

    ListNode *pNode = head;
    while (pNode != nullptr)
    {
        nodes.push(pNode);
        pNode = pNode->next;
    }

    while (!nodes.empty())
    {
        pNode = nodes.top();
        res.emplace_back(pNode->val);
        nodes.pop();
    }

    return res;
}

// 使用递归实现
void reversePrint2(ListNode *head)
{
    if (head->next != nullptr)
    {
        reversePrint(head->next);
    }

    cout << head->val << endl;
}

// 修改链表结构
void reversePrint3(ListNode *head)
{
    if (head == nullptr)
        return;

    // ListNode *nextNode;
    ListNode *node = head;
    ListNode *preNode = nullptr;
    ListNode *nextNode = head;

    while (nextNode != nullptr)
    {
        nextNode = node->next;      // 记录下一个节点
        node->next = preNode;       // 将当前节点的下一个节点改为上一个节点
        preNode = node;             // 链修改完成，将上一个节点移至当前节点，为下一个链修改作准备
        if(nextNode!=nullptr)       // 如果下一个节点不为空，当前节点下移
            node = nextNode;
    }

    while(node!=nullptr)
    {
        cout << node->val << endl;
        node = node -> next;
    }
}

int main()
{
    ListNode head(10);
    ListNode node2(20);
    ListNode node3(30);
    ListNode node4(40);
    head.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = nullptr;
    // 栈实现测试代码
    // vector<int> res = reversePrint(&head);
    // for (auto item : res)
    //     cout << item << endl;

    // 递归实现测试
    // reversePrint2(&head);

    reversePrint3(&head);
    return 0;
}
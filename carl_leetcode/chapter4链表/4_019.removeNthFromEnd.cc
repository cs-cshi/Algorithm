#include <iostream>
#include "ListNode.hh"

using std::cout;
using std::endl;

class Solution
{
public:
    // 删除链表倒数第 n 个节点
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *fast = dummyHead;
        ListNode *slow = dummyHead;
        while (n-- && fast != nullptr)
            fast = fast->next;

        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;
    }

    // 打印链表
    void printLinkedList(ListNode *head)
    {
        ListNode *cur = head;
        while (cur != nullptr)
        {
            cout << cur->val << "  ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    Solution *solution = new Solution();
    solution->printLinkedList(node1);
    node1 = solution->removeNthFromEnd(node1, 2);
    solution->printLinkedList(node1);
}
/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

进阶：
你是否可以使用 O(1) 空间解决此题？
*/
#include <iostream>

using std::cout;
using std::endl;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle2(ListNode *head)
{
    ListNode *fast = head;       // 快指针，每次走两步
    ListNode *slow = head;       // 慢指针，每次走一步
    ListNode *cycle_head = head; // 记录头节点指针，每次快慢指针从头节点开始走
    bool pos = false;            // 标识：当前头节点是否在环中
    bool has_cycle = false;      // 标识：是否存在环

    while (!pos)
    {
        // 判断是否存在环
        while (slow->next != nullptr && fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == cycle_head || slow == cycle_head) // 判断当前头节点是否在环中
                pos = true;

            if (fast == slow) // 判断是否存在环
            {
                has_cycle = true;
                break;
            }
        }

        if ((has_cycle && pos) || cycle_head->next == nullptr) // 找到存在环的头节点，或者遍历结束
            break;
        else
        {
            cycle_head = cycle_head->next;
            fast = cycle_head;
            slow = cycle_head;
        }
    }
    if (pos)
        return cycle_head;
    return nullptr;
}

ListNode *detectCycle(ListNode *head)
{
    if (!head)
        return nullptr;

    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *cycle_head = head;

    while (slow->next != nullptr && fast->next != nullptr && fast->next->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }

    if (fast->next && slow->next && fast->next->next)
    {
        while (cycle_head != slow)
        {
            slow = slow->next;
            cycle_head = cycle_head->next;
        }
        return cycle_head;
    }

    return nullptr;
}

int main()
{
    ListNode *head = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(4);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;
    ListNode *ans = detectCycle(head);
    if (ans)
        cout << ans->val << endl;
}
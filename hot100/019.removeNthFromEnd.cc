// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 19. 删除链表的倒数第 N 个结点
// 快慢指针思路：快指针先移动 N+1 步，然后再同步移动
// N+1步：这样快指针遍历完指针时，慢指针是倒数第 N+1 个结点，方便删除
// 但要注意控制边界
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // 链表只有一个结点时，题干给出了 n >= 1
    if (!head->next)
        return head->next;

    ListNode *pre = head;  // 快指针
    ListNode *last = head; // 慢指针

    // 快指针移动 n+1 步
    while (n != -1)
    {
        // 当删除的结点是首节点时。n >= 1
        if (!pre)
            return head->next;

        pre = pre->next;
        n--;
    }

    // 快慢指针同步移动
    while (pre)
    {
        pre = pre->next;
        last = last->next;
    }

    last->next = last->next->next;

    return head;
}

int main()
{
    ListNode node1(1);
    ListNode *p1 = &node1;
    // node1.next = nullptr;

    ListNode node2(2);
    node1.next = &node2;
    // node2.next = nullptr;

    ListNode node3(3);
    node2.next = &node3;

    ListNode node4(4);
    node3.next = &node4;

    ListNode node5(5);
    node4.next = &node5;
    node5.next = nullptr;

    ListNode *result = removeNthFromEnd(p1, 2);
}
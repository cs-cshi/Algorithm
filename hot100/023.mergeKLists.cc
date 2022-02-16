/*
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。
*/

#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 合并两个有序链表
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1 || !list2) // list1 或 list2 为空
        return list1 ? list1 : list2;

    ListNode head;          // 合并链表的头结点
    ListNode *tail = &head; // 指向头结点的指针
    ListNode *aPtr = list1; // 避免破坏 list1
    ListNode *bPtr = list2; // 避免破坏 list2

    while (aPtr && bPtr)
    {
        if (aPtr->val > bPtr->val)
        {
            tail->next = bPtr;
            bPtr = bPtr->next;
        }
        else
        {
            tail->next = aPtr;
            aPtr = aPtr->next;
        }
        tail = tail->next;
    }

    // 此时可以直接把剩下的链表附在合并的链表后，不需要一个一个结点加
    /*
    while (aPtr)
    {
        tail->next = aPtr;
        aPtr = aPtr->next;
    }

    while (bPtr)
    {
        tail->next = bPtr;
        bPtr = bPtr->next;
    }
    */

    aPtr ? tail->next = aPtr : tail->next = bPtr;

    return head.next;
}

// 使用二分法，连接 lists 中所有链表
ListNode *merge(vector<ListNode *> &lists, int left, int right)
{
    if (left == right)
        return lists[left];
    else if (left > right)
        return nullptr;
    int mid = (left + right) / 2;
    return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    return merge(lists, 0, lists.size() - 1);
}

int main()
{
    ListNode node11(1);
    ListNode *p1 = &node11;

    ListNode node12(3);
    node11.next = &node12;

    ListNode node13(4);
    node12.next = &node13;
    node13.next = nullptr;

    ListNode node21(2);
    ListNode *p2 = &node21;

    ListNode node22(5);
    node21.next = &node22;

    ListNode node23(8);
    node22.next = &node23;
    node23.next = nullptr;

    ListNode node31(6);
    ListNode *p3 = &node31;

    ListNode node32(7);
    node31.next = &node32;

    ListNode node33(9);
    node32.next = &node33;
    node33.next = nullptr;

    vector<ListNode *> lists = {p1, p2, p3};
    ListNode *result = mergeKLists(lists);

    while (result)
    {
        cout << result->val << endl;
        result = result->next;
    }

    return 0;
}
/**
 * BM16 删除有序链表中重复的元素-II
 * 给出一个升序排序的链表，删除链表中的所有重复出现的元素，只保留原链表中只出现一次的元素。
 * 例如：
 * 给出的链表为 1→2→3→3→4→4→5, 返回 1→2→5.
 * 给出的链表为 1→1→1→2→3, 返回 2→3.
 */

#include "bits/stdc++.h"
#include "ListNode.hh"

using namespace std;

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution
{
public:
    /**
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *deleteDuplicates(ListNode *head)
    {
        // write code here
        if (head == nullptr)
            return nullptr;

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *cur = dummyHead->next;
        ListNode *pre = dummyHead;
        bool flag = false; // 标识是否出现值相等区间
        while (cur && cur->next)
        {
            if (cur->val == cur->next->val)
            {
                flag = true;
                cur->next = cur->next->next;
            }
            else
            {
                if (flag) // 出现过值相相等区间，删除该区间
                {
                    pre->next = cur->next;
                    flag = false;
                }
                else
                    pre = cur;
                cur = cur->next;
            }
        }

        if (flag) // 链表尾端出现重复，cur->next 为空退出循环
            pre->next = cur->next;

        ListNode *tmp = dummyHead->next;
        delete dummyHead;
        return tmp;
    }
};
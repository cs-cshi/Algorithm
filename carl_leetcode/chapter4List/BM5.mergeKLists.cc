/**
 * BM5 合并k个已排序的链表
 * 合并 k 个升序的链表并将结果作为一个升序的链表返回其头节点。
 * 数据范围：节点总数满足 0 ≤ n ≤ 10^5
 * 链表个数满足 1 ≤ k ≤ 10^5
 * 每个链表的长度满足 1 ≤ len ≤ 200，每个节点的值满足 ∣val∣<=1000
 * 要求：时间复杂度 O(nlogk)
 * 链接：https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6?tpId=295&tqId=724&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "ListNode.hh"
#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    // 归并排序归并思想，两两归并
    ListNode *mergeKLists1(vector<ListNode *> &lists)
    {
        queue<ListNode *> que;
        for (ListNode *node : lists)
            que.push(node);
        int len = que.size();
        while (1)
        {
            len = que.size();
            if (len == 1) // 归并到了最上层，只剩下一个结点
                break;
            while (len > 0) // 当前层结点数，数的层次遍历思想
            {
                if (len > 1) // 剩下多个结点
                {
                    ListNode *list1 = que.front();
                    que.pop();

                    ListNode *list2 = que.front();
                    que.pop();
                    que.push(mergeTwoList(list1, list2));
                }
                else // 只剩下一个节点，将节点弹出后重新入队列，保证有序
                {
                    que.push(que.front());
                    que.pop();
                }
                len -= 2;
            }
        }
        return que.front();
    }

    //合并两个排序链表
    ListNode *mergeTwoList(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == nullptr)
            return pHead2;

        if (pHead2 == nullptr)
            return pHead1;

        ListNode *cur1 = pHead1, *cur2 = pHead2;
        ListNode *dummyHead = new ListNode(0); // 虚头节点
        ListNode *cur = dummyHead;
        while (cur1 && cur2)
        {
            if (cur1->val > cur2->val)
            {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            else
            {
                cur->next = cur1;
                cur1 = cur1->next;
            }
            cur = cur->next;
        }

        if (cur1)
            cur->next = cur1;

        if (cur2)
            cur->next = cur2;

        ListNode *tmp = dummyHead->next;
        delete dummyHead;
        return tmp;
    }

    ListNode *mergeKLists2(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        vector<int> nums;
        for (ListNode *list : lists)
        {
            while (list)
            {
                nums.push_back(list->val);
                list = list->next;
            }
        }
        sort(nums.begin(), nums.end());
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        for (int num : nums)
        {
            cur->next = new ListNode(num);
            cur = cur->next;
        }
        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }
};
/**
 * BM2 链表内指定区间反转
 * 将一个节点数为 size 链表 m 位置到 n 位置之间的区间反转，要求时间复杂度O(n)，空间复杂度O(1)。
 * 例如：
 * 给出的链表为 1→2→3→4→5→NULL, m=2,n=4,
 * 返回 1→4→3→2→5→NULL.
 * 数据范围： 链表长度 0<size≤1000，0<m≤n≤size，链表中每个节点的值满足 ∣val∣≤1000
 * 要求：时间复杂度 O(n)，空间复杂度 O(n)
 * 进阶：时间复杂度 O(n)，空间复杂度 O(1)
 */

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

#include "ListNode.hh"

class Solution
{
public:
    /**
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        // write code here
        ListNode *preNode = nullptr; // 区间之前的一个节点
        ListNode *startNode = head;  // 区间开始节点
        ListNode *endNode = head;    // 区间结束节点

        if (m == n)
            return head;
        // 定位区间开始节点
        while (--m && --n && endNode)
        {
            preNode = startNode;
            startNode = startNode->next;
            endNode = endNode->next;
        }

        // 定位区间结束节点
        while (--n)
            endNode = endNode->next;
        ListNode *endNextNode = endNode->next;
        // cout << startNode->val << endl;
        // cout << endNode->val << endl;

        // 反转 [startNode, endNode] 区间
        ListNode *pre = endNextNode;
        ListNode *tmp = nullptr;
        ListNode *cur = startNode;
        while (cur != endNextNode)
        {
            // cout << cur -> val << endl;
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        //  反转区间不是从头结点开始
        if (preNode)
        {
            preNode->next = pre;
            return head;
        }
        // 反转区间从头结点开始
        return pre;
    }
};
/**
 * BM13 判断一个链表是否为回文结构
 * 给定一个链表，请判断该链表是否为回文结构。
 * 回文是指该字符串正序逆序完全一致。
 * 数据范围： 链表节点数 0 ≤ n ≤10^5，链表中每个节点的值满足val∣≤ 10^7
 * 链接：https://www.nowcoder.com/practice/3fed228444e740c8be66232ce8b87c2f?tpId=295&tqId=1008769&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj%3Ftab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295
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
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode *head)
    {
        // write code here
        ListNode *slow = head;
        ListNode *fast = head;
        // 快慢指针，使慢指针遍历到链表中点。如果链表为偶数个节点，慢指针指向下半个链表的表头，如果为级数，指向中点
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 链表总节点奇数个
        if (fast)
            slow = slow->next;
        fast = reverse(slow);
        slow = head;
        while (fast)
        {
            if (slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }

    // 反转 pHead 链表
    ListNode *reverse(ListNode *pHead)
    {
        ListNode *pre = nullptr;
        ListNode *tmp = nullptr;
        ListNode *cur = pHead;
        while (cur)
        {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
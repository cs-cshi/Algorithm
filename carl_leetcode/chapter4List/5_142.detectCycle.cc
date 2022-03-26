#include "ListNode.hh"

class Solution
{
public:
    // 判断链表是否有环，有环则找到环的入口节点
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;      // 快指针，一次走两步
        ListNode *slow = head;      // 慢指针，一次走一步
        while (fast != nullptr && fast->next != nullptr)    // 为 nullptr 说明无环
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)   // 快慢指针相遇，存在环
            {
                ListNode *index1 = head;    // 从链表头开始
                ListNode *index2 = fast;    // 从相遇节点开始
                // 新的两个指针同时一步一步走，下次相遇的节点就是入口
                while(index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;     // 无环
    }

        // 判断链表是否有环，有环则找到环的入口节点
    ListNode *detectCycle2(ListNode *head)
    {
        ListNode *fast = head;      // 快指针，一次走两步
        ListNode *slow = head;      // 慢指针，一次走一步
        while (fast != nullptr && fast->next != nullptr)    // 为 nullptr 说明无环
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)   // 快慢指针相遇，存在环。慢指针回到头，快指针不动，两个指针一步一步走，下次相遇就是环入口
            {
                slow = head;    // 从链表头开始
                // ListNode *index2 = fast;    // 从相遇节点开始
                // 新的两个指针同时一步一步走，下次相遇的节点就是入口
                while(slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;     // 无环
    }
};
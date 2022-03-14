#include <iostream>

using std::cout;
using std::endl;

class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int val) : val(val), next(nullptr) {}
        ListNode(int val, ListNode *next1) : val(val), next(next1) {}
    };

    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr; // 上一个节点
        ListNode *cur = head;    // 当前节点
        ListNode *tmp = nullptr; // 保存 cur 下一个节点
        while (cur)
        {
            tmp = cur->next;
            cur->next = pre; // 反转
            pre = cur;       // 更新
            cur = tmp;
        }
        return pre;
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
    Solution::ListNode *node1 = new Solution::ListNode(1);
    Solution::ListNode *node2 = new Solution::ListNode(2);
    Solution::ListNode *node3 = new Solution::ListNode(3);
    Solution::ListNode *node4 = new Solution::ListNode(4);
    Solution::ListNode *node5 = new Solution::ListNode(5);
    Solution::ListNode *node6 = new Solution::ListNode(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    Solution *solution = new Solution();
    solution->printLinkedList(node1);
    node1 = solution->reverseList(node1);
    solution->printLinkedList(node1);
}
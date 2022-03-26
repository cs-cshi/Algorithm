/**
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 使用虚头结点
ListNode *removeElements(ListNode *head, int val)
{
    ListNode *dummyHead = new ListNode(); // 虚头节点
    dummyHead->next = head;

    ListNode *cur = dummyHead;
    while (cur->next != nullptr)
    {
        if (cur->next->val == val)
        {
            ListNode *tmp = cur->next;
            cur->next = cur->next->next; // 脱链
            delete tmp;                  // 删除链表
        }
        else
            cur = cur->next;
    }
    head = dummyHead->next;
    delete dummyHead;
    return head;
}

// 不使用虚头结点
ListNode *removeElements(ListNode *head, int val)
{
    // 当头结点的值等于 val
    while (head != nullptr && head->val == val)
    {
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
    }

    // 头结点值不等于 val 
    ListNode *cur = head;
    while (cur != nullptr && cur->next != nullptr)
    {
        if (cur->next->val == val)
        {
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        else
            cur = cur->next;
    }
    return head;
}
/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    ListNode *cur = new ListNode(0);
    ListNode *head;

    ListNode *cur1 = l1;
    ListNode *cur2 = l2;
    head = l1->val <= l2->val ? l1 : l2;
    while (cur1 != nullptr && cur2 != nullptr)
    {
        if (cur1->val <= cur2->val)
        {
            cur->next = cur1;
            cur = cur->next;
            cur1 = cur1->next;
        }
        else
        {
            cur->next = cur2;
            cur = cur->next;
            cur2 = cur2->next;
        }
    }
    //连接最后一个节点。
    if (cur1 == nullptr)
        cur->next = cur2;
    else
        cur->next = cur1;
    return head;
}

int main()
{
    return 0;
}
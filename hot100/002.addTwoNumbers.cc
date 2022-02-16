/*
给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = nullptr; // result 链表的头指针
    ListNode *tail = nullptr; // result 链表的尾指针，用于新增 Node
    int carry = 0;            //进位

    // 当两个链表都没有遍历完时
    while (l1 != nullptr && l2 != nullptr)
    {
        int sum = l1->val + l2->val + carry;
        if (head == nullptr) // 开始构建 result 链表
        {
            head = tail = new ListNode(sum % 10);
        }
        else
        {
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        carry = sum / 10; // 更新进位

        l1 = l1->next;
        l2 = l2->next;
    }

    // l2 遍历完，而 l1 没有遍历完的情形
    while (l1 != nullptr)
    {
        // 注意仍然需要判断是否进位
        int sum = l1->val + carry;
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
        l1 = l1->next;
        carry = sum / 10;
    }

    // l1 遍历玩，而 l2 没有遍历完的情形
    while (l2 != nullptr)
    {
        int sum = l2->val + carry;
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
        l2 = l2->next;
        carry = sum / 10;
    }

    // 判断最后一位是否发生了进位
    if (carry != 0)
    {
        tail->next = new ListNode(carry);
    }

    return head;
}

ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2)
{
    ListNode *list1 = l1;
    ListNode *list2 = l2;
    ListNode *sumList = new ListNode(0);
    ListNode *node = sumList;
    int carry = 0; // 进位

    while (list1 && list2)
    {
        int val = (list1->val + list2->val + carry) % 10; // 当前位值
        carry = (list1->val + list2->val + carry) / 10;   // 当前进位
        node->next = new ListNode(val);
        node = node->next;
        list1 = list1->next;
        list2 = list2->next;
    }

    while (list1)
    {
        int val = (list1->val + carry) % 10;
        carry = (list1->val + carry) / 10;
        node->next = new ListNode(val);
        node = node->next;
        list1 = list1->next;
    }

    while (list2)
    {
        int val = (list1->val + carry) % 10;
        carry = (list1->val + carry) / 10;
        node->next = new ListNode(val);
        node = node->next;
        list2 = list2->next;
    }

    if (carry != 0)
        node->next = new ListNode(carry);

    return sumList->next;
}

int main()
{
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;

    ListNode *node21 = new ListNode(5);
    ListNode *node22 = new ListNode(6);
    ListNode *node23 = new ListNode(4);
    node21->next = node22;
    node22->next = node23;

    addTwoNumbers2(node1, node21);
    return 0;
}
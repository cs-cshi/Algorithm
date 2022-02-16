/*
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：
    你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

ListNode *sortList(ListNode *head)
{
    if (!head)
        return head;
    sortList(head, nullptr);
}

/*
    链表的归并排序
    head：子链表串的第一个结点
    tail：子链表串最后一个结点的后一个结点
*/
ListNode *sortList(ListNode *head, ListNode *tail)
{
    // 递归退出条件，即划分至只有一个结点
    if (head->next == tail)
    {
        head->next = nullptr; // 断链
        return head;
    }

    // 使用快慢指针找出链表的 mid 结点
    // slow 最终得到的是真实 mid 的后一个结点
    // fast 最终得到的是最后一个结点的后一个结点
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != tail)
    {
        fast = fast->next;
        slow = slow->next;
        if (fast != tail)
            fast = fast->next;
    }

    ListNode *mid = slow;   // mid 是第二个链表的头结点
    return mergeList(sortList(head, mid), sortList(mid, tail));
}

ListNode *mergeList(ListNode *list1, ListNode *list2)
{
    ListNode *dummyHead = new ListNode(0);
    ListNode *merge_temp = dummyHead;
    ListNode *list1_temp = list1;
    ListNode *list2_temp = list2;
    while (list1_temp && list2_temp)
    {
        if (list1_temp->val <= list2_temp->val)
        {
            merge_temp->next = list1_temp;
            list1_temp = list1_temp->next;
        }
        else
        {
            merge_temp->next = list2_temp;
            list2_temp = list2_temp->next;
        }
        merge_temp = merge_temp->next;
    }

    if (list1_temp)
        merge_temp->next = list1_temp;

    if (list2_temp)
        merge_temp->next = list2_temp;

    return dummyHead->next;
}

// 自底向上
ListNode *sortList2(ListNode *head)
{
    if (!head)
        return head;
    int length = 0;
    ListNode *node = head;
    while (node)
    {
        length++;
        node = node->next;
    }
}

/*
ListNode *sortList2(ListNode *head)
{
    if (head == nullptr)
    {
        return head;
    }
    int length = 0;
    ListNode *node = head;
    while (node != nullptr)
    {
        length++;
        node = node->next;
    }
    ListNode *dummyHead = new ListNode(0, head);
    for (int subLength = 1; subLength < length; subLength <<= 1)
    {
        ListNode *prev = dummyHead, *curr = dummyHead->next;
        while (curr != nullptr)
        {
            ListNode *head1 = curr;
            for (int i = 1; i < subLength && curr->next != nullptr; i++)
            {
                curr = curr->next;
            }
            ListNode *head2 = curr->next;
            curr->next = nullptr;
            curr = head2;
            for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++)
            {
                curr = curr->next;
            }
            ListNode *next = nullptr;
            if (curr != nullptr)
            {
                next = curr->next;
                curr->next = nullptr;
            }
            ListNode *merged = mergeList(head1, head2);
            prev->next = merged;
            while (prev->next != nullptr)
            {
                prev = prev->next;
            }
            curr = next;
        }
    }
    return dummyHead->next;
}
*/

ListNode *sortList2(ListNode *head)
{
    if (!head)
        return head;

    int length = 0;         // 链表总长度
    ListNode *node = head;
    while (node)
    {
        length++;
        node = node->next;
    }

    ListNode *dummyHead = new ListNode(0, head);    // 指向第一个结点

    // 自底向上合并
    for (int subLeng = 1; subLeng < length; subLeng <<= 1)
    {
        ListNode *prev = dummyHead;
        ListNode *cur = dummyHead->next;    // 整个链表遍历结点，确保一次遍历
        
        while (cur)
        {
            ListNode *head1 = cur;  // 第一次子链表头

            for (int i = 1; i < subLeng && cur != nullptr && cur->next != nullptr; i++)     // 遍历完第一个 subLength 长度的子链表
                cur = cur->next;

            ListNode *head2 = cur->next;    // 第二个子链表头
            cur->next = nullptr;    // 第一个 subLength 长度子链表断链
            cur = head2;            

            for (int i = 1; i < subLeng && cur != nullptr && cur->next != nullptr; i++)     // 遍历完第二个 subLength 长度的子链表
                cur = cur->next;

            ListNode *next = nullptr;  // 剩余未两两归并结点的首结点

            if (cur)    // 存在第二个子链表
            {
                next = cur->next;
                cur->next = nullptr;    //  断链
                cur = next;
            }

            ListNode *merged = mergeList(head1,head2);  // 合并一组子链表
            prev->next = merged;    // 建链，将每组链表重新建链
            while(prev->next)
                prev = prev->next;
        }
    }
    return dummyHead->next;
}

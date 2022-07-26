/**
 * 输出单向链表中倒数第k个结点
 * 输入说明
 * 1 输入链表结点个数
 * 2 输入链表的值
 * 3 输入k的值
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct ListedNode {
    int val;
    ListedNode* next;
    ListedNode(int val): val(val), next(nullptr) {}
    ListedNode(int val, ListedNode* next): val(val), next(next) {}
};

int inverseKthNode(ListedNode* dummyNode, int k) {
    ListedNode* temp = dummyNode;
    ListedNode* temp2 = dummyNode;
    while (k-- && temp) {
        temp = temp->next;
    }

    if (!temp) {
        cout << -1 << endl;
        return -1;
    }

    while (temp) {
        temp = temp->next;
        temp2 = temp2->next;
    }
    cout << temp2->val << endl;
    return 0;
}

int main() {
    int len = 0;
    while (cin >> len) {
        int num;
        ListedNode* dummyNode = new ListedNode(0);
        ListedNode* tempNode = dummyNode;
        while (len--) {
            cin >> num;
            tempNode -> next = new ListedNode(num);
            tempNode = tempNode -> next;
        }
        int k;
        cin >> k;
        inverseKthNode(dummyNode, k);
    }
}
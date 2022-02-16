/*
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。
*/
#include <vector>
#include <stack>

using std::stack;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

// 先序遍历
void preorderTraversal(TreeNode *root, vector<TreeNode *> &pre_vector)
{
    if (root != NULL)
    {
        pre_vector.push_back(root);
        preorderTraversal(root->left, pre_vector);
        preorderTraversal(root->right, pre_vector);
    }
}

/*
1. 对二叉树进行先序遍历，将先序遍历结点存在 vector<TreeNode *> 中
2. 遍历 vector，构造单链表
*/
void flatten2(TreeNode *root)
{
    vector<TreeNode *> pre_vector;
    TreeNode *tmp_node = root;
    preorderTraversal(root, pre_vector);
    for (int i = 1; i < pre_vector.size(); i++)
    {
        tmp_node->left = nullptr;
        tmp_node->right = pre_vector[i];
        tmp_node = tmp_node->right;
    }
}

// 使用迭代法实现先序遍历
void flatten3(TreeNode *root)
{
    vector<TreeNode *> pre_vector;
    stack<TreeNode *> stk;

    TreeNode *node = root;
    while (node != nullptr || !stk.empty())
    {
        while (node != nullptr)
        {
            stk.push(node);
            pre_vector.emplace_back(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        node = node->right;
    }
    node = root;
    for (int i = 1; i < pre_vector.size(); i++)
    {
        node->left = nullptr;
        node->right = pre_vector[i];
        node = node->right;
    }
}

// 使用迭代法实现先序遍历,遍历同时构建新的链表
// 关键点：之前的先序遍历，压栈之后会破坏二叉树结构而丢失右结点，因此对于当前结点，可以先将右结点压栈，再将左结点压栈
void flatten4(TreeNode *root)
{
    if (root == nullptr)
        return;

    stack<TreeNode *> stk;
    TreeNode *pre_node = nullptr;
    TreeNode *current_node = nullptr;

    stk.push(root);

    while (!stk.empty())
    {
        current_node = stk.top(); // 当前结点，栈顶
        stk.pop();

        if (pre_node != nullptr) // 初始构建链表，当前结点为 root ，pre 为空时
        {
            pre_node->right = current_node;
            pre_node->left = nullptr;
        }

        if (current_node->right)
            stk.push(current_node->right);
        if (current_node->left)
            stk.push(current_node->left);
        pre_node = current_node;
    }
}

/*
利用先驱结点，O(1)空间复杂度完成
1. 记录当前结点的左结点 left，将作为链表的下一个结点
2. 在左子树中找到先驱 predecessor，将先驱的右孩子赋为当前节点的右孩子
3. 将当前结点的左孩子置空，右孩子设为 left，这样链表的第一个结点构造好，并且树的结构的变化不影响后续操作
*/
void flatten(TreeNode *root)
{
    TreeNode *predecessor = nullptr; // 当前结点的先驱
    TreeNode *current_node = root;   // 当前操作结点
    while (current_node != nullptr)
    {
        if (current_node->left) // 当前节点左子树存在，若不存在，不需要改变结构，直接处理下一个结点
        {
            TreeNode *next_node = current_node->left; // 记录当前结点的左孩子，将作为当前结点的右孩子（先序遍历顺序）
            predecessor = next_node;                  // 在左子树中找先驱结点

            while (predecessor->right)                // 找到先驱结点
                predecessor = predecessor->right;

            // 构造完链表第一个结点，同时不影响原始树结构的遍历顺序
            predecessor->right = current_node->right;
            current_node->left = nullptr;
            current_node->right = next_node;
        }
        current_node = current_node->right;
    }
}

int main()
{
    TreeNode root(3);
    TreeNode node1(9);
    root.left = &node1;
    TreeNode node2(20);
    root.right = &node2;
    node1.left = nullptr;
    node1.right = nullptr;
    TreeNode node3(15);
    TreeNode node4(7);
    node2.left = &node3;
    node2.right = &node4;
    flatten(&root);
    return 0;
}
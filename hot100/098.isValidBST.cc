/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/
#include <iostream>
#include <limits>
#include <stack>
#include <vector>

using std::numeric_limits;
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

bool check(TreeNode *root, long long lower, long long upper)
{
    if (root == nullptr)
        return true;

    if (root->val <= lower || root->val >= upper)
        return false;

    return check(root->left, lower, root->val) && check(root->right, root->val, upper);
}

// 中序遍历
bool inorderTraversal(TreeNode *root)
{
    long pre = numeric_limits<long>::min();  // 需要用 long，否则如果中序遍历第一个结点其值等于 INT_MIN，不好判断
    // vector<int> ans;
    stack<TreeNode *> stk;
    while (root != nullptr || !stk.empty())
    {
        while(root!=nullptr)
        {
            stk.push(root);
            root = root -> left;
        }
        root = stk.top();
        // ans.emplace_back(root->val);
        if( pre >= root->val )
            return false;
        pre = root->val;
        stk.pop();
        root = root->right;
    }
    return true;
}

bool isValidBST(TreeNode *root)
{
    // bool ans = true;
    // check(root, ans);
    // return ans;
    long long_min = numeric_limits<long>::min();
    long long_max = numeric_limits<long>::max();
    // return check(root, long_min, long_max);
    return inorderTraversal(root);
}

int main()
{
    TreeNode root(5);
    TreeNode node1(4);
    root.left = &node1;
    TreeNode node2(6);
    root.right = &node2;
    node1.left = nullptr;
    node1.right = nullptr;
    TreeNode node3(3);
    TreeNode node4(7);
    node2.left = &node3;
    node2.right = &node4;
    bool ret = isValidBST(&root);
    if (ret)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    return 0;
}
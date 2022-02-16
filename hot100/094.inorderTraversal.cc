/*
    给定一个二叉树的根节点 root ，返回它的中序遍历。
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode *root, vector<int> ans)
{
    if (!root)
        return;
    inorder(root->left, ans);
    ans.emplace_back(root->val);
    inorder(root->right, ans);
}

// 递归
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    inorder(root, ans);
}

// 迭代
vector<int> inorderTraversal2(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> stk;
    while (root != nullptr || !stk.empty())
    {
        while (root != nullptr)
        {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        ans.emplace_back(root->val);
        root = root->right;
    }
    return ans;
}

// morris 中序遍历
vector<int> inorderTraversal3(TreeNode *root)
{
    vector<int> ans;
    TreeNode *predecessor = nullptr;
    while (root != nullptr)
    {
        if (root->left != nullptr)
        {
            // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
            predecessor = root->left;
            while (predecessor->right != nullptr && predecessor->right != root)
                predecessor = predecessor->right;
            // 让 predecessor 的右指针指向 root，继续遍历左子树
            if (predecessor->right == nullptr)
            {
                predecessor->right = root;
                root = root->left;
            }
            else // 说明左子树已经访问完了，我们需要断开链接
            {
                ans.emplace_back(root->val);
                predecessor->right = nullptr;
                root = root->right;
            }
        }
        // 如果没有左孩子，则直接访问右孩子
        else
        {
            ans.emplace_back(root->val);
            root = root->right;
        }
    }
}
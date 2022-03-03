/**
 * 给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
 * 你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。
 * 链接：https://leetcode-cn.com/problems/search-in-a-binary-search-tree
 */

class Solution
{
public:
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
        TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    };

    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *node = root;
        while (node != nullptr)
        {
            if (val > node->val)
                node = node->right;
            else if (val < node->val)
                node = node->left;
            else
                return node;
        }
        return nullptr;
    }
};
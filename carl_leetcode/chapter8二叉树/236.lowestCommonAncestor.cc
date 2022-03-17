/**
 * 236. 二叉树的最近公共祖先
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree
 */
#include "treeNode.hh"

class Solution
{
public:
    // struct TreeNode
    // {
    //     int val;
    //     TreeNode *left;
    //     TreeNode *right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //     TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    //     TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    // };

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return traverseByRecursion(root, p, q);
    }

    // 返回当前子树是否存在指定节点
    TreeNode *traverseByRecursion(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;

        if (root == p || root == q) // 当前子树存在公共节点
            return root;

        TreeNode *left = traverseByRecursion(root->left, p, q); // 左子树存在的公共节点
        TreeNode *right = traverseByRecursion(root->right, p, q);

        // 对当前节点处理逻辑，最终返回的是在这里
        if (left != nullptr && right != nullptr)      // 左右子树都存在，最近公共祖先
            return root;                              // 不断回溯上去，这个值会是最终返回结果，只是有可能回溯过程中将其赋值给了 left/right
        else if (left != nullptr && right == nullptr) // 最近公共祖先在左子树
            return left;
        else if (left == nullptr && right != nullptr) // 最近公共祖先在右子树
            return right;
        else
            return nullptr; // 不存在最近公共祖先
    }
};
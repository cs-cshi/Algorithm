/**
 * 450. 删除二叉搜索树中的节点
 * 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
 * 一般来说，删除节点可分为两个步骤：
 *     - 首先找到需要删除的节点；
 *     - 如果找到了，删除它。
 * 链接：https://leetcode-cn.com/problems/delete-node-in-a-bst
 */
#include "treeNode.hh"

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        while (cur != nullptr)
        {
            if (cur->val == key)
                break;
            pre = cur;
            if (key > cur->val)
                cur = cur->right;
            else
                cur = cur->left;
        }

        if (pre == nullptr)
            return deleteNodeOperation(cur);

        if (pre->left != nullptr && pre->left->val == key)
            pre->left = deleteNodeOperation(pre->left);

        if (pre->right != nullptr && pre->right->val == key)
            pre->right = deleteNodeOperation(pre->right);

        return root;
    }

    // 通过返回 target 的左孩子 or 右孩子删除 target
    TreeNode *deleteNodeOperation(TreeNode *target)
    {
        if (target == nullptr)
            return nullptr;
        if (target->right == nullptr)
            return target->left;
        TreeNode *cur = target->right;
        while (cur->left)
            cur = cur->left;
        cur->left = target->left;
        return target->right;
    }
};

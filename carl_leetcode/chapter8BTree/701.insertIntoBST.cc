/**
 * 701. 二叉搜索树中的插入操作
 * 给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。
 * 注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。
 *
 * 链接：https://leetcode-cn.com/problems/insert-into-a-binary-search-tree
 */
#include "treeNode.hh"

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *newNode = new TreeNode(val);
        if (root == nullptr)
            return newNode;
        TreeNode *preNode = nullptr;
        TreeNode *cur = root;
        while (cur != nullptr)
        {
            preNode = cur;
            if (val < cur->val)
                cur = cur->left;
            else
                cur = cur->right;
        }

        if (val < preNode->val)
            preNode->left = newNode;
        else
            preNode->right = newNode;
        return root;
    }

    TreeNode *insertIntoBSTByRecursion(TreeNode *root, int val)
    {
    }

    void traversal(TreeNode *cur, TreeNode *parent, int val)
    {
        if (cur == nullptr)
        {
            if (val < parent->val)
                parent->left = new TreeNode(val);
            else
                parent->right = new TreeNode(val);
            return;
        }

        parent = cur;
        if(val < cur->val)
            traversal(cur->left,parent,val);
        if(val > cur->val)
            traversal(cur->right,parent,val);
        return;
    }
};
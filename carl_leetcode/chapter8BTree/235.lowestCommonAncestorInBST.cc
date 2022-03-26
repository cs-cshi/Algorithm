/**
 * 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree
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
        return findByInterate(root, p, q);
    }

    TreeNode *findByInterate(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *ancestorNode = root;

        TreeNode *low = p->val < q->val ? p : q;
        TreeNode *upper = low == p ? q : p;

        while (ancestorNode != nullptr)
        {
            // if (ancestorNode->val > low->val && ancestorNode->val < upper->val)
            //     return ancestorNode;
            // else if (ancestorNode->val > upper->val)
            //     ancestorNode = ancestorNode->left;
            // else if (ancestorNode->val < low->val)
            //     ancestorNode = ancestorNode->right;
            if (ancestorNode->val > upper->val)
                ancestorNode = ancestorNode->left;
            else if (ancestorNode->val < low->val)
                ancestorNode = ancestorNode->right;
            else
                return ancestorNode;
        }
        return nullptr;
    }
};
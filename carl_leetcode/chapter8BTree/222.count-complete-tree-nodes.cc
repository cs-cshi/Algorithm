/**
 * 222. 完全二叉树的节点个数
 * 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
 * 完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。
 * 链接：https://leetcode.cn/problems/count-complete-tree-nodes
 */

#include "treeNode.hh"
#include <iostream>

using namespace std;

class Solution
{
public:
    /**
     * 思路：
     * 对于每个节点，计算左子树和右子树的深度
     *   - 若左右子树深度相等，左子树必然是满二叉树，递归计算右子树节点个数
     *   - 若左右子树深度相差一，右子树必然是满二叉树，递归计算左子树节点个数
    */
    int countNodes(TreeNode *root)
    {
        int leftDepth = getDepth(root->left);
        cout << leftDepth << endl;
        int rightDepth = getDepth(root->right);

        if (leftDepth == rightDepth)
            return ((1 << leftDepth) - 1) + countNodes(root->right) + 1;
        else
            return countNodes(root->left) + ((1 << rightDepth) - 1) + 1;
    }

    // 完全二叉树计算深度
    int getDepth(TreeNode *root)
    {
        TreeNode *node = root;
        int count = 0;
        while (node)
        {
            count++;
            node = node->left;
        }
        return count;
    }
};
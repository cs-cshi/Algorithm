/**
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。(一个二叉树每个节点的左右两个子树的高度差的绝对值不超过 1 。)
 * 链接：https://leetcode-cn.com/problems/balanced-binary-tree/
 */
#include "treeNode.hh"
#include <algorithm>
#include <stack>

using std::abs;
using std::max;
using std::stack;

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return getDepth(root) == -1 ? false : true;
    }

    int getDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftDepth = getDepth(root->left);   // 左
        int rightDepth = getDepth(root->right); // 右
        if (leftDepth == -1 || rightDepth == -1)
            return -1;

        if (abs(rightDepth - leftDepth) > 1)
            return -1;

        return 1 + max(leftDepth, rightDepth);
    }

    // 迭代法，求高度
    int getDepth2(TreeNode *root)
    {
        stack<TreeNode *> stk;
        if (root == nullptr)
            return 0;
        stk.push(root);
        int result = 0;
        int depth = 0;
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            if (node)
            {
                stk.push(node);
                stk.push(nullptr);
                depth++;
                if (node->right)
                    stk.push(node->right);
                if (node->left)
                    stk.push(node->left);
            }
            else
            {
                node = stk.top();
                stk.pop();
                depth--;
            }
            result = result > depth ? result : depth;
        }
        return result;
    }

    // 两边回溯，效率很低
    bool isBalanced2(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            if (abs(getDepth2(node->left) - getDepth2(node->right)) > 1)
                return false;

            if (node->left)
                stk.push(node->left);
            if (node->right)
                stk.push(node->right);
        }
        return true;
    }
};
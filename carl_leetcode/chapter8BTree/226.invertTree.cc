/**
 * 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
 * 链接：https://leetcode-cn.com/problems/invert-binary-tree/
 */

#include "treeNode.hh"
#include <algorithm>
#include <stack>

using std::stack;
using std::swap;

class Solution
{
public:
    // Definition for a binary tree node.
    // struct TreeNode
    // {
    //     int val;
    //     TreeNode *left;
    //     TreeNode *right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    //     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    // };

    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    TreeNode *invertTree2(TreeNode *root)
    {
        stack<TreeNode *> stk;
        if (root == nullptr)
            return root;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            swap(node->left, node->right);
            if (node->left)
                stk.push(node->left);
            if (node->right)
                stk.push(node->right);
        }
        return root;
    }
};
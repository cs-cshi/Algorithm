/**
 * 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
 * 链接：https://leetcode-cn.com/problems/invert-binary-tree/
 */

#include "treeNode.hh"
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

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
        invertTreePreorderTraversalByRecursion(root);
        return root;
    }

    // 先序遍历递归
    void invertTreePreorderTraversalByRecursion(TreeNode *root)
    {
        if (root == nullptr)
            return;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
    }

    // 先序遍历迭代
    void invertTreePreorderTraversalByIteration(TreeNode *root)
    {
        stack<TreeNode *> stk;
        if (root == nullptr)
            return;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            swap(node->left, node->right);
            if (node->right)
                stk.push(node->right);
            if (node->left)
                stk.push(node->left);
        }
    }

    TreeNode *levelOrder(TreeNode *root)
    {
        queue<TreeNode *> que;
        if (!root)
            return root;
        que.push(root);
        while (!que.empty())
        {
            int levelSize = que.size();
            while (levelSize--)
            {
                TreeNode *node = que.front();
                que.pop();
                swap(node->left, node->right);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return root;
    }
};
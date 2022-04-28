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
        return invertTreePreorderTraversalByRecursion(root);
    }

    // 先序遍历递归
    TreeNode *invertTreePreorderTraversalByRecursion(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    // 先序遍历迭代
    TreeNode *invertTreePreorderTraversalByIteration(TreeNode *root)
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
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
        }
        return root;
    }
};
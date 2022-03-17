/**
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 * 链接：https://leetcode-cn.com/problems/symmetric-tree/
 */
#include "treeNode.hh"
#include <queue>

using std::queue;

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

    bool isSymmetric(TreeNode *root)
    {
        check(root->left, root->right);
    }

    // 迭代法
    bool check(TreeNode *left, TreeNode *right)
    {
        queue<TreeNode *> que;
        que.push(left);
        que.push(right);
        while (!que.empty())
        {
            left = que.front();
            que.pop();
            right = que.front();
            que.pop();
            if (!left && !right)
                continue;
            if ((!left || !right) || left->val != right->val)
                return false;

            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }
        return true;
    }

    // 递归法
    bool check2(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;

        if (!left || !right || left->val != right->val)
            return false;

        return check2(left->left, right->right) && check2(left->right, right->left);
    }
};
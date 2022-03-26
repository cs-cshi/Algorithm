/**
 * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
 * 链接：https://leetcode-cn.com/problems/path-sum/
 */
#include "treeNode.hh"
#include <iostream>

using std::cout;
using std::endl;

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

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;

        if (traversal(root, targetSum))
            return true;
        return false;
    }

    bool traversal(TreeNode *root, int count)
    {
        // count -= root->val; // 中
        if (root->left == nullptr && root->right == nullptr)
        {
            if (count == 0)
                return true;
            return false;
        }

        if (root->left)
        {
            count -= root->left->val;           // target 目标增减放在进入子树逻辑处理前，方便回溯
            if (traversal(root->left, count))   
                return true;
            count += root->left->val;
        }

        if (root->right)
        {
            count -= root->right->val;
            if (traversal(root->right, count))
                return true;
            count += root->right->val;
        }

        return false;
    }
};

int main()
{
    Solution solution;
    TreeNode *node = new TreeNode(0);
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(1);
    node->left = node1;
    node->right = node2;
    if (solution.hasPathSum(node, 0))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
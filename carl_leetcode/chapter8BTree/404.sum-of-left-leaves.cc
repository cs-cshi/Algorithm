/**
 * 404. 左叶子之和
 * 给定二叉树的根节点 root ，返回所有左叶子之和。
 */

#include "treeNode.hh"
#include <queue>

using namespace std;

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        return solveByLevelTraversal(root);
    }

    // 层序遍历，用当前层结点的左孩子是否是叶子节点来统计
    int solveByLevelTraversal(TreeNode *root)
    {
        int ans = 0;
        if (!root)
            return ans;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            TreeNode *node = que.front();
            que.pop();
            if (node->left)
            {
                que.push(node->left);
                if (!node->left->left && !node->left->right)
                    ans += node->left->val;
            }
            if (node->right)
                que.push(node->right);
        }
        return ans;
    }

    int solveByRecursion(TreeNode *root)
    {
        if (!root)
            return 0;

        int mid = 0; // 当前结点左孩子是叶子节点时的值，不是为0
        if (root->left && !root->left->left && !root->left->right)
            mid = root->left->val;

        return mid + solveByRecursion(root->left) + solveByRecursion(root->right);
    }
};
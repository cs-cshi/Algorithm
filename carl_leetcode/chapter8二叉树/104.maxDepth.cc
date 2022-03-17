/**
 * 给定一个二叉树，找出其最大深度。
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
 */
#include "treeNode.hh"
#include <queue>
#include <algorithm>

using std::queue;
using std::max;

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

    // 后序遍历，递归
    int maxDepth(TreeNode *root)
    {
        return getDepth(root);
    }

    int getDepth(TreeNode *root)
    {
        if(!root)
            return 0;
        int leftDepth = getDepth(root->left);       // 左
        int rightDepth = getDepth(root->right);     // 右
        int depth = 1+max(leftDepth,rightDepth);    // 中
        return depth;
        // 精简
        // return 1 + max(getDepth(root->left),getDepth(root->right));
    }

    // 使用层次遍历
    int maxDepth2(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> que;
        que.push(root);
        int depth = 0;
        while (!que.empty())
        {
            int queLevelSize = que.size();
            while (queLevelSize--)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};
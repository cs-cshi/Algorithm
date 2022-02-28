/**
 * 给定一个二叉树，找出其最小深度。
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 说明：叶子节点是指没有子节点的节点。
 */

#include <queue>
#include <algorithm>

using std::queue;
using std::min;

class Solution
{
public:
    // Definition for a binary tree node.
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    // 使用层次遍历
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> que;
        int minDepth = 0;
        que.push(root);
        while (!que.empty())
        {
            int queLevelSize = que.size();
            minDepth++;
            while (queLevelSize--)
            {
                TreeNode *node = que.front();
                que.pop();
                if (!(node->left) && !(node->right))
                    return minDepth;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return minDepth;
    }

    // 使用递归
    int minDepth2(TreeNode *root)
    {
        return getDepth(root);
    }

    int getDepth(TreeNode *root)
    {
        if(!root)
            return 0;

        int leftDepth = getDepth(root->left);       // 左子树深度
        int rightDepth = getDepth(root->right);     // 右子树深度

        if(!(root->left) && root->right )   // 左子树为空
            return 1 + rightDepth;
        
        if(!(root->right) && root->left)    // 右子树为空
            return 1+leftDepth;
        
        int result = 1 + min(leftDepth,rightDepth);     // 左右子树都存在，当前节点深度
        return result;
    }
};
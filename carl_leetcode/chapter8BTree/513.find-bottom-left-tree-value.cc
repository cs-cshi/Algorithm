/**
 * 513. 找树左下角的值
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 * 假设二叉树中至少有一个节点。
 */

#include "treeNode.hh"
#include <queue>

using namespace std;

class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        int ans = 0;
        if (!root)
            return ans;
        if (!root->left && !root->right)
            return root->val;

        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            bool flag = true;
            int levelSize = que.size();
            while (levelSize--)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left)
                {
                    que.push(node->left);
                    if (!node->left->left && !node->left->right && flag)
                    {
                        ans = node->left->val;
                        flag = false;
                    }
                }

                if (node->right)
                {
                    que.push(node->right);
                    if (!node->right->left && !node->right->right && flag)
                    {
                        ans = node->right->val;
                        flag = false;
                    }
                }
            }
        }
        return ans;
    }

    // 简化，层序遍历直接判断当前结点是否是叶子结点
    int findBottomLeftValue2(TreeNode *root)
    {
        int ans = 0;
        if (!root)
            return ans;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            bool flag = true;
            int levelSize = que.size();
            while (levelSize--)
            {
                TreeNode *node = que.front();
                que.pop();
                if (!node->left && !node->right && flag)
                {
                    ans = node->val;
                    flag = false;
                }
                if (node->left)
                    que.push(node->left);

                if (node->right)
                    que.push(node->right);
            }
        }
        return ans;
    }
};
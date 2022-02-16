/*
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。
*/

#include <algorithm>
#include <iostream>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

int levelOrder(TreeNode *root)
{
    std::queue<TreeNode *> que;
    int ans = 0;
    if (root)
        que.push(root);

    while (!que.empty())
    {
        int currentLevelSize = que.size();
        for (int i = 0; i < currentLevelSize; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
        ans+=1;
    }
    return ans;
}

int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;

    // if (!root->left && !root->right)
    //     return 1;

    // if (root->left && !root->right)
    //     return maxDepth(root->left) + 1;

    // if (root->right && !root->left)
    //     return maxDepth(root->right) + 1;

    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{
    TreeNode root(3);
    TreeNode node1(9);
    root.left = &node1;
    TreeNode node2(20);
    root.right = &node2;
    node1.left = nullptr;
    node1.right = nullptr;
    TreeNode node3(15);
    TreeNode node4(7);
    node2.left = &node3;
    node2.right = &node4;
    int ans = maxDepth(&root);
    std::cout << ans << std::endl;
}
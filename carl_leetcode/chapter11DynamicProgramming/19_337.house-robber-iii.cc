/**
 * 337. 打家劫舍 III
 * 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
 * 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
 * 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
 * 链接：https://leetcode.cn/problems/house-robber-iii
 */

#include "chapter8BTree/treeNode.hh"
#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    int rob(TreeNode *root)
    {
    }

    //  递归后续遍历，会超时，存在重复计算
    int robRecursion(TreeNode *root)
    {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return root->val;

        int val1 = root->val;

        // 取根节点
        if (root->left)
            val1 += robRecursion(root->left->left) + robRecursion(root->left->right);
        if (root->right)
            val1 += robRecursion(root->right->left) + robRecursion(root->right->right);

        // 跳过根节点
        int val2 = robRecursion(root->left) + robRecursion(root->right);
        return max(val1, val2);
    }

    //  递归后续遍历优化
    // 使用 map，避免节点的重复计算
    int robRecursionOptimization(TreeNode *root)
    {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return root->val;

        if(umap[root])
            return umap[root];

        int val1 = root->val;

        // 取根节点
        if (root->left)
            val1 += robRecursionOptimization(root->left->left) + robRecursionOptimization(root->left->right);
        if (root->right)
            val1 += robRecursionOptimization(root->right->left) + robRecursionOptimization(root->right->right);

        // 跳过根节点
        int val2 = robRecursionOptimization(root->left) + robRecursionOptimization(root->right);
        umap[root] = max(val1, val2);
        return max(val1, val2);
    }

private:
    unordered_map<TreeNode *, int> umap;
};
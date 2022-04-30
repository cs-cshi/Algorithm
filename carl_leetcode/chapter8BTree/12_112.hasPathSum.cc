/**
 * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
 * 链接：https://leetcode-cn.com/problems/path-sum/
 */
#include "treeNode.hh"
#include <iostream>
#include <stack>
#include <utility>

using namespace std;
// using std::cout;
// using std::endl;

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;

        if (traversal(root, targetSum))
            return true;
        return false;

        // return backtracking(root, root->val, targetSum);
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
            count -= root->left->val; // target 目标增减放在进入子树逻辑处理前，方便回溯
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

    bool backtracking(TreeNode *cur, int curSum, int target)
    {
        if (!cur->left && !cur->right)
        {
            if (curSum == target)
                return true;
            else
                return false;
        }

        if (cur->left && backtracking(cur->left, curSum + cur->left->val, target))
            return true;

        if (cur->right && backtracking(cur->right, curSum + cur->right->val, target))
            return true;

        return false;
    }

    // 迭代实现，先序遍历，本质上出了需要对 node 用 stack 实现遍历外，还需要使用存储当前 sum 的 stack
    bool hasPathSumByIteration(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;

        stack<TreeNode *> stk1;
        stack<int> stk2;
        stk1.push(root);
        stk2.push(root->val);
        while (!stk1.empty())
        {
            TreeNode *node = stk1.top();
            stk1.pop();
            int curSum = stk2.top();
            stk2.pop();
            if (!node->left && !node->right && targetSum == curSum)
                return true;

            if (node->right)
            {
                stk1.push(node->right);
                stk2.push(curSum + node->right->val);
            }

            if (node->left)
            {
                stk1.push(node->left);
                stk2.push(curSum + node->left->val);
            }
        }
        return false;
    }

    // 利用 pair<TreeNode *,int>，一个栈实现
    bool hasPathSumByIteration2(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;

        stack<pair<TreeNode *, int>> stk;
        stk.push({root, root->val});
        while (!stk.empty())
        {
            pair<TreeNode *, int> cur_pair = stk.top();
            stk.pop();
            TreeNode *cur_node = cur_pair.first;
            if (!cur_node->left && !cur_node->right && cur_pair.second == targetSum)
                return true;
            if (cur_node->left)
                stk.push({cur_node->left, cur_pair.second + cur_node->left->val});

            if (cur_node->right)
                stk.push({cur_node->right, cur_pair.second + cur_node->right->val});
        }
        return false;
    }
};

/**
 * 二叉树的前序遍历
 * 链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 */

#include "treeNode.hh"
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preorderTraversalByRecursion(root, ans);
        return ans;
    }

    // 先序遍历递归实现
    void preorderTraversalByRecursion(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;
        ans.push_back(root->val);
        preorderTraversalByRecursion(root->left, ans);
        preorderTraversalByRecursion(root->right, ans);
    }

    // 先序遍历迭代实现
    void preorderTraversalByIteration(TreeNode *root, vector<int> &ans)
    {
        stack<TreeNode *> stk;

        if(!root)
            return;

        stk.push(root);

        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            ans.push_back(node->val);
            if (node->right)
                stk.push(node->right);
            if (node->left)
                stk.push(node->left);
        }
    }
};
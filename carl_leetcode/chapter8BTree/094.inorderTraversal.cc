/**
 * 94.二叉树中序遍历
 * 链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 */

#include "treeNode.hh"
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inorderTraversalByRecursion(root, ans);
        return ans;
    }

    void inorderTraversalByRecursion(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        inorderTraversalByRecursion(root->left, ans);
        ans.push_back(root->val);
        inorderTraversalByRecursion(root->right, ans);
    }

    void inorderTraversalByIteration(TreeNode *root, vector<int> &ans)
    {
        stack<TreeNode *> stk;
        if (!root)
            return;

        // stk.push(root);
        TreeNode *cur = root;
        while (!stk.empty() || cur)
        {
            if (!cur)
            {
                cur = stk.top();
                ans.push_back(cur->val);
                stk.pop();
                cur = cur->right;
            }
            else
            {
                stk.push(cur);
                cur = cur->left;
            }
        }
    }
};
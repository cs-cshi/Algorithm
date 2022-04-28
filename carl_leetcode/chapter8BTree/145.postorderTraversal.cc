/**
 * 145.后序遍历
 * 链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
 */

#include "treeNode.hh"
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postorderTraversalByRecursion(root, ans);
        return ans;
    }

    // 后序遍历递归实现
    void postorderTraversalByRecursion(TreeNode *root, vector<int> &ans)
    {
        if(!root)
            return;
        
        postorderTraversalByRecursion(root->left,ans);
        postorderTraversalByRecursion(root->right, ans);
        ans.push_back(root->val);
    }

    // 后序遍历迭代实现
    void postorderTraversalByIteration(TreeNode *root, vector<int> &ans)
    {
        stack<TreeNode *> stk;
        TreeNode *cur = root, *prev;

        if(!root)
            return;
        
        while(!stk.empty() || cur != nullptr)
        {
            while(cur)
            {
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top();
            stk.pop();
            if(cur->right == nullptr || cur->right == prev)
            {
                ans.push_back(cur->val);
                prev = cur;
                cur = nullptr;
            }else
            {
                stk.push(cur);
                cur = cur->right;
            }
        }  
    }
};
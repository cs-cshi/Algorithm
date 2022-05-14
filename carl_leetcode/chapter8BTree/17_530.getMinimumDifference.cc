/**
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。差值是一个正数，其数值等于两值之差的绝对值。
 */
#include "treeNode.hh"
#include <stack>
#include <algorithm>

using std::min;
using std::stack;

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode *prev = nullptr;
        int ans = INT_MAX;
        getMinimumDifferenceByRecursion(root, prev, ans);
        return ans;
    }

    // 迭代，用栈实现，关键在于记录前一个结点 prev
    int getMinimumDifferenceByIterator(TreeNode *root)
    {
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        int ans = INT_MAX;
        while(!stk.empty() || cur )
        {
            if(cur)
            {
                stk.push(cur);
                cur = cur->left;
            }else
            {
                cur = stk.top();
                stk.pop();
                if(pre)
                    ans = min(ans, cur->val - pre->val);
                pre = cur;
                cur = cur->right;
            }
        }
        return ans;
    }

    // 递归实现，注意参数要用引用
    void getMinimumDifferenceByRecursion(TreeNode *root, TreeNode *&prev, int &ans)
    {
        if(!root)
            return;
        
        getMinimumDifferenceByRecursion(root->left, prev, ans);

        if(prev)
            ans = min(ans, root->val - prev->val);
        
        prev = root;

        getMinimumDifferenceByRecursion(root->right, prev, ans);
    }
};
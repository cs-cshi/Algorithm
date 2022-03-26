/**
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。差值是一个正数，其数值等于两值之差的绝对值。
 */
#include "treeNode.hh"
#include <stack>
#include <limits>
#include <algorithm>

using std::min;
using std::numeric_limits;
using std::stack;

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

    // 中序遍历，二叉搜索树本身会有序
    int getMinimumDifference(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int minimum = numeric_limits<int>::max();
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        stack<TreeNode *> stk;
        while (cur != nullptr || stk.empty())
        {
            if (cur != nullptr)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = stk.top();
                stk.pop();
                if (pre != nullptr)
                    minimum = min(minimum, cur->val - pre->val);
                pre = cur;
                cur = cur->right;
            }
        }
        return minimum;
    }
};
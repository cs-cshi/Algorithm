/**
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 * 有效 二叉搜索树定义如下：
 *    节点的左子树只包含 小于 当前节点的数。
 *    节点的右子树只包含 大于 当前节点的数。
 *    所有左子树和右子树自身必须也是二叉搜索树。
 * 链接：https://leetcode-cn.com/problems/validate-binary-search-tree
 */
#include <limits>
#include <stack>

using std::numeric_limits;
using std::stack;

class Solution
{
public:
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
        TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    };

    // 每个节点都有上界和下界
    bool isValidBST(TreeNode *root)
    {
        long longMin = numeric_limits<long>::min();
        long longMax = numeric_limits<long>::max();
        return recursion(root, longMin, longMax);
    }

    // 上界，下界
    bool recursion(TreeNode *root, long long lower, long long upper)
    {
        if (root == nullptr)
            return true;

        if (root->val <= lower || root->val >= upper)
            return false;

        return recursion(root->left, lower, root->val) && recursion(root->right, root->val, upper);
    }

    bool isValidBSTIterate(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        while (cur != nullptr || !stk.empty())
        {
            if (cur != nullptr)
            {
                stk.push(cur);
                cur = cur->left; // 左
            }
            else
            {
                cur = stk.top(); // 中
                stk.pop();
                if (pre != nullptr && pre->val >= cur->val)
                    return false;
                pre = cur; // 右
                cur = cur->right;
            }
        }
    }
};
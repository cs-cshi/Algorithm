/**
 * 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
 * 链接：https://leetcode-cn.com/problems/path-sum-ii/
 */
#include "treeNode.hh"
#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        getPath(root, targetSum - root->val, path, result);
        return result;
    }

    void getPath(TreeNode *root, int curSum, vector<int> &path, vector<vector<int>> &result)
    {
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            if (curSum == 0)    // 也可以用 curSum = targetSum 来计算，加一个参数
                result.push_back(path);
            return;
        }

        if (root->left)
        {
            getPath(root->left, curSum - root->left->val, path, result); // 也可以先 curSum -= root->left->val，递归后在回溯加回来，递归参数传 curSum
            path.pop_back();
        }

        if (root->right)
        {
            getPath(root->right, curSum - root->right->val, path, result);
            path.pop_back();
        }
    }
};
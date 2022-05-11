/**
 * 107. 二叉树的层序遍历 II
 * 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 链接：https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
*/

#include <vector>
#include "treeNode.hh"
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty())
        {
            int level_size = que.size();
            vector<int> level_val;
            while(level_size--)
            {
                TreeNode *cur = que.front();
                que.pop();
                level_val.push_back(cur->val);
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
            ans.push_back(level_val);
        }
        reverse(ans.begin(), ans.end());    // 对二维 vector 反转
        return ans;
    }
};
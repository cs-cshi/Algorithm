/**
 * 102. 层序遍历
 * 链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 */

#include "treeNode.hh"
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<vector<int>> ans;

        if(!root)
            return ans;

        que.push(root);
        while(!que.empty())
        {
            int levelSize = que.size();
            vector<int> level_ans;
            while(levelSize--)
            {
                TreeNode *node = que.front();
                que.pop();
                level_ans.push_back(node->val);
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
            ans.push_back(level_ans);
        }
        return ans;
    }
};
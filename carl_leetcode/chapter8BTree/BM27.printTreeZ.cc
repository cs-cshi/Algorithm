/**
 * BM27 按之字形顺序打印二叉树
 * 给定一个二叉树，返回该二叉树的之字形层序遍历，（第一层从左向右，下一层从右向左，一直这样交替）
 * 数据范围：0≤n≤1500,树上每个节点的val满足∣val∣<=1500
 * 要求：空间复杂度：O(n)O(n)，时间复杂度：O(n)O(n)
 */

#include "treeNode.hh"
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> ans;
        if (!pRoot)
            return ans;
        queue<TreeNode *> que;
        // int level_num = 0;
        bool flag = false;

        que.push(pRoot);

        while (!que.empty())
        {
            int level_size = que.size();
            // level_num++;
            vector<int> level_vec;
            while (level_size--)
            {
                TreeNode *cur = que.front();
                que.pop();
                level_vec.push_back(cur->val);
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
            if (flag)
                reverse(level_vec.begin(), level_vec.end());
            ans.push_back(level_vec);
            flag = !flag;
        }
        return ans;
    }
};
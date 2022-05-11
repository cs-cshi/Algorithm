/**
 * 199. 二叉树的右视图
 * 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 链接:https://leetcode.cn/problems/binary-tree-right-side-view/
 */

#include "treeNode.hh"
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    /**
     * 思路：层序遍历，每一层最后一个元素入 ans 集合
     */
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int level_size = que.size();
            while (level_size--)
            {
                TreeNode *cur = que.front();
                que.pop();
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
                if (level_size == 0) // 注意这里是0，level_size 先用于判断再自减1
                    ans.push_back(cur->val);
            }
        }
        return ans;
    }
};
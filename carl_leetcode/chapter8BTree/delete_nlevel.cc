/**
 * 腾讯音乐面试题
 * 给定一棵树和一个数组，删除树中的指定层，指定层由数组给出
 * 返回删除后该树剩余部分构成的子树
 * 如：
 *      1
 *  2       3
 *     4        5
 * 删除第二层后，构成子树的根结点分别是 1,4,5
*/

#include "treeNode.hh"
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

// 层次遍历中注意每一层如何标识
vector<TreeNode *> deleteLevelOrder(TreeNode *root, vector<int> deleteLevels)
{
    queue<TreeNode *> que;  // 层序遍历队列
    vector<TreeNode *> ans; // 删除指定层后剩下的树的根结点
    int level = 0, i = 0;
    bool isDeleteLevel = false;
    bool isDeleteLevelFarther = false;

    if (!root)
        return ans;

    sort(deleteLevels.begin(), deleteLevels.end());

    if (deleteLevels.empty()) // 不需要删除
    {
        ans.push_back(root);
        return ans;
    }

    if (deleteLevels[0] != 1) // 不需要删除第一层，树根构成子树
        ans.push_back(root);

    que.push(root);

    while (!que.empty())
    {
        level++;

        if (level + 1 == deleteLevels[i]) // 下一层是否为待删除层
            isDeleteLevelFarther = true;

        if (level == deleteLevels[i]) // 当前层为删除层
            isDeleteLevel = true;

        int levelSize = que.size();
        while (levelSize--)
        {
            TreeNode *node = que.front();
            que.pop();
            if (node->left)
            {
                que.push(node->left);
                if (isDeleteLevelFarther) // 待删除层的上一层
                    node->left = nullptr;

                if (isDeleteLevel) // 待删除层
                {
                    if (i + 1 < deleteLevels.size() && deleteLevels[i + 1] - deleteLevels[i] != 1) // 若下一层也要删除，则当前层的孩子结点不构成树
                        ans.push_back(node->left);
                }
            }
            if (node->right)
            {
                que.push(node->right);
                if (isDeleteLevelFarther) // 待删除层的上一层
                    node->left = nullptr;

                if (isDeleteLevel) // 待删除层
                {
                    if (i + 1 < deleteLevels.size() && deleteLevels[i + 1] - deleteLevels[i] != 1) // 若下一层也要删除，则当前层的孩子结点不构成树
                        ans.push_back(node->left);
                }
            }
        }
        if (isDeleteLevel) // 当前层删除
            i++;

        // 已删除所有需要删除的层
        if (i >= deleteLevels.size())
            break;
        isDeleteLevelFarther = false;
        isDeleteLevel = false;
    }
    return ans;
}
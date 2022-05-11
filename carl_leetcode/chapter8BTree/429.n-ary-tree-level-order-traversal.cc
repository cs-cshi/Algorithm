/**
 * 429. N 叉树的层序遍历
 * 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
 * 树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
 */

#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) : val(_val) {}

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    /**
     * 层序遍历
     */
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            int level_size = que.size();
            vector<int> level_val_vec;
            while (level_size--)
            {
                Node *node = que.front();
                que.pop();
                level_val_vec.push_back(node->val);

                if (!(node->children).empty())
                {
                    for (const auto child : node->children)
                        que.push(child);
                }
            }
            ans.push_back(level_val_vec);
        }
        return ans;
    }
};
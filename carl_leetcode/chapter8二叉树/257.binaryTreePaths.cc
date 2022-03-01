/**
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
 * 链接：https://leetcode-cn.com/problems/binary-tree-paths/
 */
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution
{
public:
    // Definition for a binary tree node.
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        vector<int> path;
        traversal(root, path, result);
        return result;
    }

    // 先序、中序、后序本质上是深度优先遍历，参数 path 的增加弹出体现了回溯的过程
    void traversal(TreeNode *cur, vector<int> &path, vector<string> &result)
    {
        path.push_back(cur->val);      // 中
        if (!cur->left && !cur->right) // 叶子节点
        {
            string pathStr;
            for (int i = 0; i < path.size() - 1; i++)
            {
                pathStr += std::to_string(path[i]);
                pathStr += "->";
            }
            pathStr += std::to_string(path[path.size() - 1]);
            result.emplace_back(pathStr);
            return;
        }

        if (cur->left) // 左
        {
            traversal(cur->left, path, result);
            path.pop_back();
        }

        if (cur->right) // 右
        {
            traversal(cur->right, path, result);
            path.pop_back();
        }
    }

    // path 使用 string 类型代替 vector<int> 类型，减少 vector 的 pop 过程，但实际上每次递归时都会新建一个新的 string 对象，内存上可能会增加
    void traversal2(TreeNode *cur, string path, vector<string> &result)
    {
        path += std::to_string(cur->val);
        if (cur->left == nullptr && cur->right == nullptr)
        {
            result.emplace_back(path);
            return;
        }
        if (cur->left)
            traversal2(cur->left, path + "->", result);

        if (cur->right)
            traversal2(cur->right, path + "->", result);
    }
};
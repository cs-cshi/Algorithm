/**
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 * 链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 */
#include "treeNode.hh"
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution
{
public:
    // Definition for a binary tree node.
    // struct TreeNode
    // {
    //     int val;
    //     TreeNode *left;
    //     TreeNode *right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    //     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    // };

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0 || inorder.size() == 0)
            return nullptr;

        return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    TreeNode *traversal(vector<int> &preorder, int preorderBegin, int preorderEnd, vector<int> &inorder, int inorderBegin, int inorderEnd)
    {
        if (preorderBegin == preorderEnd)
            return nullptr;

        int rootValue = preorder[preorderBegin];
        TreeNode *node = new TreeNode(rootValue);

        if (preorderEnd - preorderBegin == 1)
            return node;

        int delimiterIndex = inorderBegin;
        for (; delimiterIndex <= inorderEnd; delimiterIndex++)
        {
            if (rootValue == inorder[delimiterIndex])
                break;
        }

        // 切割中序遍历
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        // 切割先序遍历
        int leftPreorderBegin = preorderBegin + 1;
        int leftPreorderEnd = preorderBegin + delimiterIndex - inorderBegin + 1;
        int rightPreorderBegin = leftPreorderEnd;
        int rightPreorderEnd = preorderEnd;

        node->left = traversal(preorder, leftPreorderBegin, leftPreorderEnd, inorder, leftInorderBegin, leftInorderEnd);
        node->right = traversal(preorder, rightPreorderBegin, rightPreorderEnd, inorder, rightInorderBegin, rightInorderEnd);
        return node;
    }

    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right, unordered_map<int, int> &map)
    {
        // 子树大小为0
        if (preorder_left > preorder_right)
            return nullptr;
        // 找出根结点并建立根结点
        int root_value = preorder[preorder_left];
        TreeNode *root = new TreeNode(preorder[preorder_left]);

        // 找出前序遍历中左右子树起始、结束索引
        // 找出中序遍历中左右子树起始、结束索引
        int inorder_root_index = map[root_value];
        int left_tree_size = inorder_root_index - inorder_left;

        // 根结点左右子树建树
        root->left = buildTreeHelper(preorder, inorder, preorder_left + 1, preorder_left + left_tree_size, inorder_left, inorder_root_index - 1, map);
        root->right = buildTreeHelper(preorder, inorder, preorder_left + left_tree_size + 1, preorder_right, inorder_root_index + 1, inorder_right, map);

        return root;
    }

    TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder)
    {
        int size = inorder.size();
        unordered_map<int, int> map;
        for (int i = 0; i < size; i++)
            map[inorder[i]] = i;
        return buildTreeHelper(preorder, inorder, 0, size - 1, 0, size - 1, map);
    }
};
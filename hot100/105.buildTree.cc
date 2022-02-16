/*
给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。
*/
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::unordered_map;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int size = inorder.size();
    unordered_map<int, int> map;
    for (int i = 0; i < size; i++)
        map[inorder[i]] = i;
    return buildTreeHelper(preorder, inorder, 0, size - 1, 0, size - 1, map);
}

int main()
{
    return 0;
}
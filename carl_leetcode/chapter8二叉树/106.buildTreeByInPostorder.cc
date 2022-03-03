/**
 * 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
 * 链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
 */
#include <vector>

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

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0)
            return nullptr;
        // return traversal(inorder, postorder);
        return traversal2(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }

    TreeNode *traversal(vector<int> &inorder, vector<int> &postorder)
    {
        // 如果后序遍历数组为空,说明是空节点
        if (postorder.size() == 0)
            return nullptr;

        // 后序遍历最后一个节点为根节点
        int rootValue = postorder.back();
        TreeNode *node = new TreeNode(rootValue);
        postorder.pop_back();

        // 当前节点为叶子节点
        if (postorder.size() == 0)
            return node;

        // 找出中序遍历中根节点的索引位置，作为分割点
        int rootIndexInInorder = 0;
        for (; rootIndexInInorder < inorder.size(); rootIndexInInorder++)
        {
            if (inorder[rootIndexInInorder] == rootValue)
                break;
        }

        // 切割中序遍历，左闭右开原则
        //注意：
        // 1. 使用其他 vecotr 容器来初始化新的 vector 容器，参数索引是左闭右开原则
        // 2. vector 的 end() 方法返回的是容器最后一个元素的后一个位置，即为nullptr
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndexInInorder);    // [0, rootIndexInorder)
        vector<int> rightInorder(inorder.begin() + rootIndexInInorder + 1, inorder.end()); // [rootIndexInorder+1,end)

        // 切割后序遍历
        // [0,leftInorder.size())
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // [leftInorder.size(),end)
        vector<int> rightPostOrder(postorder.begin() + leftInorder.size(), postorder.end());

        node->left = traversal(leftInorder, leftPostorder);
        node->right = traversal(rightInorder, rightPostOrder);
        return node;
    }

    // 速度和内存会小很多
    TreeNode *traversal2(vector<int> &inorder, int inorderBegin, int inorderEnd, vector<int> &postorder, int postorderBegin, int postorderEnd)
    {
        // 空节点
        if (postorderBegin == postorderEnd)
            return nullptr;

        int rootValue = postorder[postorderEnd-1];  //右边是开区间
        TreeNode *node = new TreeNode(rootValue);
        postorderEnd--; // 后序遍历弹出根节点

        if (postorderBegin == postorderEnd)
            return node;

        int delimiterIndex = inorderBegin;
        for (; delimiterIndex < inorder.size(); delimiterIndex++)
        {
            if (inorder[delimiterIndex] == rootValue)
                break;
        }

        // 切割中序数组，最开始进入递归时，End 会传入最后一个元素位置的后一个位置
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        // 切割后序数组
        int leftPostorderBegin = postorderBegin;
        int leftPostorderEnd = postorderBegin + delimiterIndex - inorderBegin;
        int rightPostorderBegin = postorderBegin + delimiterIndex - inorderBegin;
        int rightPostorderEnd = postorderEnd;

        node->left = traversal2(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
        node->right = traversal2(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);

        return node;
    }
};

int main()
{
    Solution solution;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    Solution::TreeNode *root = nullptr;
    solution.buildTree(inorder, postorder);
}
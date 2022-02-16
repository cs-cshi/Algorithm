#include <iostream>
#include <vector>

using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);
TreeNode *buildTreeCore(vector<int> &preorder, int startPreorder, int endPreorder, vector<int> &inorder, int startInorder, int endInorder);

int main()
{
    vector<int> preorver{1, 2, 3, 7, 3, 5, 6, 8};
    vector<int> inorder{4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode *binaryTree = buildTree(preorver, inorder);
    return 0;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.empty() || inorder.empty())
        return nullptr;

    return buildTreeCore(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

TreeNode *buildTreeCore(vector<int> &preorder, int startPreorder, int endPreorder, vector<int> &inorder, int startInorder, int endInorder)
{
    // 构建根节点
    int rootValue = preorder[startPreorder];
    TreeNode *rootNode = new TreeNode(rootValue);
    rootNode->val = rootValue;
    rootNode->left = nullptr;
    rootNode->right = nullptr;

    // 子树只有一个节点
    if (startPreorder == endPreorder && startInorder == endInorder)
        return rootNode;

    // 寻找根节点在中序遍历中的索引位置
    int rootInorder = startInorder;
    while (inorder[rootInorder] != rootValue)
        ++rootInorder;

    int leftLength = rootInorder - startInorder;    // 左子树节点个数
    // 构建左子树
    if (leftLength > 0)
        rootNode->left = buildTreeCore(preorder, startPreorder + 1, startPreorder + leftLength, inorder, startInorder, rootInorder - 1);

    
    int rightLength = endInorder - rootInorder;     // 右子树节点个数
    // 构建右子树
    if (rightLength > 0)
        rootNode->right = buildTreeCore(preorder, startPreorder + leftLength + 1, endPreorder, inorder, rootInorder + 1, endInorder);

    return rootNode;
}

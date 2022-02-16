/*
路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。
*/
#include <algorithm>
#include <limits>

using std::max;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxGain(TreeNode *root, int &max_sum)
{
    if (!root)
        return 0;

    // 计算当前左右子节点最大贡献值
    int left_gain = max(maxGain(root->left, max_sum), 0);
    int right_gain = max(maxGain(root->right, max_sum), 0);

    // 以当前结点为根结点路径和
    int current_path = root->val + left_gain + right_gain;

    // 更新最大路径和
    max_sum = max(current_path, max_sum);

    // 返回当前结点的最大贡献值
    return root->val + max(left_gain, right_gain);
}

int maxPathSum(TreeNode *root)
{
    int max_sum = std::numeric_limits<int>::min();
    maxGain(root,max_sum);
    return max_sum;
}

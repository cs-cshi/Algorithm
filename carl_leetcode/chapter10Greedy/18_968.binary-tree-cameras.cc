/**
 * 968. 监控二叉树
 * 给定一个二叉树，我们在树的节点上安装摄像头。
 * 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
 * 计算监控树的所有节点所需的最小摄像头数量。
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    /**
     * 从下往上看，局部最优：让叶子节点的父节点安摄像头，所用摄像头最少，整体最优：全部摄像头数量所用最少！
     */
    int minCameraCover(TreeNode *root)
    {
        count = 0;
        if (traversal(root) == 0)
            count++;
        return count;
    }

    /**
     * 0 : 无覆盖
     * 1 : 有摄像头
     * 2 : 有覆盖
     */
    int traversal(TreeNode *cur)
    {
        if (cur == nullptr)
            return 2;
        int left = traversal(cur->left);
        int right = traversal(cur->right);

        if (left == 0 || right == 0)
        {
            count++;
            return 1;
        }
        else if (left == 2 && right == 2)
            return 0;
        else
            return 2;
    }

private:
    int count;
};

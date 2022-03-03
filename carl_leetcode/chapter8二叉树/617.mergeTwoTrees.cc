/**
 * 想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。
 * 合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。
 * 返回合并后的二叉树。
 */
#include <queue>

using std::queue;

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

    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        return traversal(root1, root2);
    }

    TreeNode *traversal(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;
        TreeNode *root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }

    TreeNode *mergeTreesByLevelTracersal(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;
        queue<TreeNode *> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty())
        {
            TreeNode *node1 = que.front();
            que.pop();
            TreeNode *node2 = que.front();
            que.pop();
            node1->val += node2->val;

            // 两棵树左子树都不为空
            if (node1->left != nullptr && node2->left != nullptr)
            {
                que.push(node1->left);
                que.push(node2->left);
            }

            // 两棵树右子树都不为空
            if (node1->right != nullptr && node2->right != nullptr)
            {
                que.push(node1->right);
                que.push(node2->right);
            }

            // root1 左子树为空， root2 左子树不为空
            if (node1->left == nullptr && node2->left != nullptr)
                node1->left = node2->left;

            // root1 右子树为空， root2 右子树不为空
            if (node1->right == nullptr && node2->right != nullptr)
                node1->right = node2->right;
        }
        return root1;
    }
};
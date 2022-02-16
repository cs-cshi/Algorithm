/*
给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
    1
   / \
  2   2
   \   \
   3    3

进阶：
    你可以运用递归和迭代两种方法解决这个问题吗？
*/

#include <queue>
#include <vector>

using std::queue;
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

bool check(TreeNode *left, TreeNode *right)
{
    queue<TreeNode *> que;
    que.push(left);
    que.push(right);
    while (!que.empty())
    {
        left = que.front();
        que.pop();
        right = que.front();
        que.pop();
        if (!left && !right)
            continue;
        if ((!left || !right) || left->val != right->val)
            return false;

        que.push(left->left);
        que.push(right->right);

        que.push(left->right);
        que.push(right->left);
    }
    return true;
}

// 递归思路
bool check2(TreeNode *left,TreeNode *right)
{
    if(!left&&!right)
        return true;
    
    if(!left || !right || left->val != right->val)
        return false;
    
    return (left->val == right->val) && check(left->left,right->right) && check(left->right,right->left);
}

bool isSymmetric(TreeNode *root)
{
    if (!root->left && !root->right) // 左右子树都不存在
        return true;

    if (!root->left || !root->right || root->left->val != root->right->val) // 左子树不存在，或右子树不存在，或左右子树不对称
        return false;

    // return check(root,root);
    return check(root->left, root->right);
}

int main() {}
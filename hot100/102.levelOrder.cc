/*
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
*/
#include <vector>
#include <queue>

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

// 层序遍历，并操作层数
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;

    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty())
    {
        int currentLevelSize = que.size();  // 用于对当前层进行操作
        ans.push_back(vector<int>());  // 定义这一层的空 vector
        for (int i = 0; i < currentLevelSize; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            ans.back().emplace_back(node->val);
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
    }
    return ans;
}

int main()
{
    TreeNode root(3);
    TreeNode node1(9);
    root.left = &node1;
    TreeNode node2(20);
    root.right = &node2;
    node1.left = nullptr;
    node1.right = nullptr;
    TreeNode node3(15);
    TreeNode node4(7);
    node2.left = &node3;
    node2.right = &node4;
    levelOrder(&root);
    return 0;
}
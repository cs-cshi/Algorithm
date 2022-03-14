#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using std::queue;
using std::reverse;
using std::stack;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// 前序遍历
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> result;
    preorderTraversalByRecursion(root, result);
    return result;
}

// 前序遍历递归实现
void preorderTraversalByRecursion(TreeNode *root, vector<int> &vec)
{
    if (root == nullptr)
        return;
    vec.push_back(root->val);
    preorderTraversalByRecursion(root->left, vec);
    preorderTraversalByRecursion(root->right, vec);
}

// 2022.03.05 练习
vector<int> preorderTraversalByIterate2(TreeNode *root)
{
    vector<int> result;
    if (root == nullptr)
        return result;
    stack<TreeNode *> stk;
    stk.push(root);
    while (!stk.empty())
    {
        TreeNode *cur = stk.top();
        stk.pop();
        result.push_back(cur->val);
        if (cur->right)
            stk.push(cur->right);
        if (cur->left)
            stk.push(cur->left);
    }
    return result;
}

// 前序遍历迭代实现
vector<int> preorderTraversalByIterate(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> stk;
    if (root == nullptr)
        return result;
    stk.emplace(root);
    while (!stk.empty())
    {
        TreeNode *node = stk.top();
        stk.pop();
        result.push_back(node->val);
        if (node->right)
            stk.emplace(node->right);
        if (node->left)
            stk.emplace(node->left);
    }
    return result;
}

// 统一将结点按照遍历顺序加入栈，再弹出，通过栈是否为空来判断遍历是否结束
vector<int> preorderTraversalByIterateUnite(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> stk;
    if (root == nullptr)
        return result;
    stk.push(root);
    while (!stk.empty())
    {
        TreeNode *node = stk.top();
        if (node) // 保证结点按照先序遍历条件入栈
        {
            stk.pop(); // 将该节点弹出，之后做了将做了标记的压入
            if (node->right)
                stk.push(node->right);
            if (node->left)
                stk.push(node->left);
            stk.push(node);
            stk.push(nullptr);
        }
        else
        {
            stk.pop();
            node = stk.top();
            stk.pop();
            result.push_back(node->val);
        }
    }
    return result;
}

// 中序遍历
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> result;
    inorderTraversalByRecursion(root, result);
    return result;
}

// 中序遍历递归实现
void inorderTraversalByRecursion(TreeNode *root, vector<int> &vec)
{
    if (root == nullptr)
        return;
    inorderTraversalByRecursion(root->left, vec);
    vec.push_back(root->val);
    inorderTraversalByRecursion(root->right, vec);
}

vector<int> inorderTraversalByIterate2(TreeNode *root)
{
    vector<int> result;
    if (root == nullptr)
        return result;
    stack<TreeNode *> stk;
    // stk.push(root);          // 不需要先 push
    TreeNode *cur = root;
    while (cur != nullptr || !stk.empty())
    {
        if (cur != nullptr)
        {
            stk.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = stk.top();
            stk.pop();
            result.emplace_back(cur->val);
            cur = cur->right;
        }
    }
}

// 中序遍历迭代实现
vector<int> inorderTraversalByIterate(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> stk;
    if (root == nullptr)
        return result;
    TreeNode *cur = root;
    while (cur != nullptr || !stk.empty())
    {
        if (cur != nullptr)
        {
            stk.emplace(cur);
            cur = cur->left; // 左
        }
        else
        {
            cur = stk.top();
            stk.pop();
            result.push_back(cur->val); // 中
            cur = cur->right;           // 右
        }
    }
    return result;
}

// 统一将结点按照遍历顺序加入栈，再弹出，通过栈是否为空来判断遍历是否结束
vector<int> inorderTraversalByIterateUnite(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> stk;
    if (root == nullptr)
        return result;
    stk.push(root);
    while (!stk.empty())
    {
        TreeNode *node = stk.top();
        if (node)
        {
            stk.pop();
            if (node->right)
                stk.push(node->right);
            // 访问了当前结点，将他的左右子树按照遍历顺序要求压入了栈中，但还未处理，需要标识
            stk.push(node);
            stk.push(nullptr);
            if (node->left)
                stk.push(node->left);
        }
        else // 为空，标识符，说明下个结点是已经访问过但没有处理的，注意访问过说明会按要求加入到栈中
        {
            stk.pop();
            node = stk.top();
            stk.pop();
            result.push_back(node->val);
        }
    }
    return result;
}

// 后序遍历
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> result;
    postorderTraversalByRecursion(root, result);
    return result;
}

// 后序遍历递归实现
void postorderTraversalByRecursion(TreeNode *root, vector<int> &vec)
{
    if (root == nullptr)
        return;
    postorderTraversalByRecursion(root->left, vec);
    postorderTraversalByRecursion(root->right, vec);
    vec.push_back(root->val);
}

// 后序遍历迭代实现
// 前序遍历：中-左-右，调整左右顺序：中-右-左，反转：左-右-中（后序）
vector<int> postorderTraversalByIterate(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> stk;
    if (root == nullptr)
        return result;
    stk.push(root);
    while (!stk.empty())
    {
        TreeNode *node = stk.top();
        stk.pop();
        result.push_back(node->val);
        if (node->left)
            stk.emplace(node->left);
        if (node->right)
            stk.emplace(node->right);
    }
    reverse(result.begin(), result.end());
    return result;
}

// 统一将结点按照遍历顺序加入栈，再弹出，通过栈是否为空来判断遍历是否结束
vector<int> postorderTraversalByIterateUnite(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> stk;
    if (root == nullptr)
        return result;
    stk.push(root);
    while (!stk.empty())
    {
        TreeNode *node = stk.top();
        if (node)
        {
            stk.push(nullptr);
            if (node->right)
                stk.push(node->right);
            if (node->left)
                stk.push(node->left);
        }
        else
        {
            stk.pop();
            node = stk.top();
            stk.pop();
            result.push_back(node->val);
        }
    }
    return result;
}

// 层次遍历中注意每一层如何标识
vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<TreeNode *> que;
    vector<vector<int>> result;
    if (!root)
        return result;
    que.push(root);
    while (!que.empty())
    {
        vector<int> levelVec;
        int levelSize = que.size();
        while (levelSize--)
        {
            TreeNode *node = que.front();
            que.pop();
            levelVec.push_back(node->val);
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
        result.push_back(levelVec);
    }
    return result;
}
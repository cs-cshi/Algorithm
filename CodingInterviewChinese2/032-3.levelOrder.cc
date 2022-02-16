#include <vector>
#include <deque>
#include <iostream>

using std::cout;
using std::deque;
using std::endl;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == nullptr)
        return {};

    deque<TreeNode *> my_deque;
    my_deque.push_front(root);
    int level = 1;
    vector<vector<int>> res;

    while (!my_deque.empty())
    {
        vector<int> tmp;
        // 奇数层->队列头部，子节点从右向左->队列尾部
        if (level & 1 == 1)
        {
            int size = my_deque.size();
            while (size--)
            {
                TreeNode *fp = my_deque.front();
                if (fp->right)
                    my_deque.push_back(fp->right);
                if (fp->left)
                    my_deque.push_back(fp->left);
                tmp.push_back(fp->val);
                my_deque.pop_front();
            }
            level++;
        }
        // 偶数层->队列尾部，子节点从左向右->队列头部
        else // (level & 1 == 1)
        {
            int size = my_deque.size();
            while (size--)
            {
                TreeNode *bp = my_deque.back();
                if (bp->left)
                    my_deque.push_front(bp->left);
                if (bp->right)
                    my_deque.push_front(bp->right);
                tmp.push_back(bp->val);
                my_deque.pop_back();
            }
            level++;
        }
        res.push_back(tmp);
    }
    return res;
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
    vector<vector<int>> ans = levelOrder(&root);
    for (auto items : ans)
    {
        for (auto item : items)
            cout << item << " ";
        cout << endl;
    }
    return 0;
}

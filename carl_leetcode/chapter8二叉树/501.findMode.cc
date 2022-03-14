/**
 * 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
 * 如果树中有不止一个众数，可以按 任意顺序 返回。
 * 假定 BST 满足如下定义：
 *     结点左子树中所含节点的值 小于等于 当前节点的值
 *     结点右子树中所含节点的值 大于等于 当前节点的值
 *     左子树和右子树都是二叉搜索树
 * 链接：https://leetcode-cn.com/problems/find-mode-in-binary-search-tree
 */
#include <vector>
#include <stack>
#include <unordered_map>
#include <utility>
#include <algorithm>

using std::stack;
using std::unordered_map;
using std::vector;
using std::pair;
using std::sort;

class Solution
{
public:
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
        TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    };

    vector<int> findMode(TreeNode *root)
    {
        return findModeByIterate(root);
    }

    /**
     * 中序遍历
     * 用 pre 记录上一个节点，比较上一个节点与当前节点的值并记录连续相等的次数 count
     * 使用 maxCount 记录最大次数，若当前 count 大于了 maxCount，清空 result
     */
    vector<int> findModeByIterate(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
            return result;
        int maxCount = 0;
        int count = 0;
        TreeNode *pre = nullptr;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (cur != nullptr || !stk.empty())
        {
            if (cur != nullptr)
            {
                stk.push(cur); // 左
                cur = cur->left;
            }
            else
            {
                cur = stk.top(); // 中（每个节点都可以是中），节点处理
                stk.pop();
                if (pre == nullptr)
                    count = 1;
                else if (pre->val == cur->val)
                    count++;
                else
                    count = 1;

                if (count == maxCount)
                    result.push_back(cur->val);

                if (count > maxCount)
                {
                    result.clear();
                    maxCount = count;
                    result.push_back(cur->val);
                }
                pre = cur;
                cur = cur->right; // 右
            }
        }
        return result;
    }

    bool static cmp(const pair<int, int>& a,const pair<int,int> &b)
    {
        return a.second > b.second;
    }

    // 普通二叉树中频率出现最高的节点的值
    vector<int> findModeInCommonBinaryTree(TreeNode *root)
    {
        unordered_map<int,int> map;
        vector<int> result;
        if(root==nullptr)
            return result;
        traversalBT(root,map);
        vector<pair<int,int>> vec(map.begin(),map.end());
        sort(vec.begin(),vec.end(),cmp);
        result.push_back(vec[0].first);
        for(int i=1;i<vec.size();i++)
        {
            if(vec[i].second == vec[0].second)
                result.push_back(vec[i].first);
            else 
                break;
        }
        return result;
    }

    void traversalBT(TreeNode *root, unordered_map<int, int> &map)
    {
        if (root == nullptr)
            return;
        map[root->val]++;
        traversalBT(root->left, map);
        traversalBT(root->right, map);
        return;
    }
};
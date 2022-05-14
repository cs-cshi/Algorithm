/**
 * 654. 最大二叉树
 * 给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:
 *   1. 创建一个根节点，其值为 nums 中的最大值。
 *   2. 递归地在最大值 左边 的 子数组前缀上 构建左子树。
 *   3. 递归地在最大值 右边 的 子数组后缀上 构建右子树。
 * 返回 nums 构建的 最大二叉树 。
 * 链接：https://leetcode.cn/problems/maximum-binary-tree
 */

#include "treeNode.hh"
#include <vector>

using namespace std;

class Solution
{
public:
    // 先序/后序 + 中序 构造二叉树简化版，思路一致
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return traversal(nums, 0, nums.size());
    }

    // [)
    TreeNode *traversal(vector<int> &nums, int begin, int end)
    {
        // 退出条件
        if (begin >= end)
            return nullptr;

        // 寻找根节点
        int rootIndex = findMaxValueIndex(nums, begin, end);
        TreeNode *root = new TreeNode(nums[rootIndex]);

        // 当前结点为叶子结点
        if (end - begin == 1)
            return root;

        // 划分左右子树
        int leftBegin = begin;
        int leftEnd = rootIndex;
        int rightBegin = rootIndex + 1;
        int rightEnd = end;

        // 构建当前结点左右孩子
        root->left = traversal(nums,leftBegin, leftEnd);
        root->right = traversal(nums, rightBegin,rightEnd);
        
        return root;
    }

    // [)
    int findMaxValueIndex(vector<int> &nums, int begin, int end)
    {
        int maxIndex = begin;

        for (int i = begin; i < end; i++)
            if (nums[i] > nums[maxIndex])
                maxIndex = i;

        return maxIndex;
    }
};
/**
 * 108. 将有序数组转换为二叉搜索树
 * 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
 * 高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
 * 链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
 */

#include "treeNode.hh"
#include <vector>

using std::vector;

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() < 1)
            return nullptr;
        return traversal(nums, 0, nums.size() - 1);
    }

    TreeNode *traversal(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        int mid = (right - left) >> 1 + left;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = traversal(nums, left, mid - 1);
        node->right = traversal(nums, mid + 1, right);
        return node;
    }
};
/**
 * 135. 分发糖果
 * n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
 * 你需要按照以下要求，给这些孩子分发糖果：
 *   - 每个孩子至少分配到 1 个糖果。
 *   - 相邻两个孩子评分更高的孩子会获得更多的糖果。
 * 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
 * 链接：https://leetcode-cn.com/problems/candy
 */

#include <vector>
#include <algorithm>

using std::max;
using std::vector;

class Solution
{
public:
    // 从左至右，从右至左，两次贪心
    int candy(vector<int> &ratings)
    {
        // 从左往右，确定左界
        vector<int> candyVec(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
                candyVec[i] = candyVec[i - 1] + 1;
        }

        // 从右往左，确定右界，同时考虑左界确定最终值
        for (int i = ratings.size() - 2; i >= 0; i--)
            if (ratings[i] > ratings[i + 1])
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);

        int result = 0;
        for (int i = 0; i < candyVec.size(); i++)
            result += candyVec[i];

        return result;
    }
};
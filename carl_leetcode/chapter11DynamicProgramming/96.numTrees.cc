/**
 * 96. 不同的二叉搜索树
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
 * 链接:https://leetcode-cn.com/problems/unique-binary-search-trees/
 */

#include <vector>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    int numTrees(int n)
    {
        // dp[i]：i个节点构成不同二叉搜索树个数
        // dp[i] += dp[j-1]*dp[i-j]  j∈(1,i)
        // 初始化：dp[0] = 1,dp[1] = 1
        // 顺序，从前往后

        vector<int> dp(n + 1, 0);   // 不能初始化为 1
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
                cout << dp[i] << " = " << dp[j - 1] << " * " << dp[i - j] << endl;
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution solution;
    solution.numTrees(3);
}
/*
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
https://leetcode-cn.com/problems/unique-binary-search-trees/
*/

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

/*
G(n): 长度为 nn 的序列能构成的不同二叉搜索树的个数。
F(i, n): 以 i 为根、序列长度为 n 的不同二叉搜索树个数 (1≤i≤n)。

G(n) = i 从 1~n 的 F(i,n) 值累加和
F(i,n) = G(i-1) 与 G(n-i) 的笛卡尔积，即 G(i-1)*G(n-i)

那么 G(n) = i 从 1~n 的 G(i-1)*G(n-i) 的累加和
*/
int numTrees(int n)
{
    vector<int> G(n + 1, 0);
    G[0] = 1;
    G[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            G[i] += G[j - 1] * G[i - j];
    }
    return G[n];
}

int main()
{
    int ans = numTrees(1);
    cout << ans << endl;
    return 0;
}
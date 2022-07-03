# 动规问题
![](https://img-blog.csdnimg.cn/20210117171307407.png)

## 动规五部曲：
1. 确定 dp 数组（dp table）以及下标的含义
2. 确定递推公式
3. dp 数组如何初始化
4. 确定遍历顺序
5. 举例推导 dp 数组

## 背包问题
###  递推公式
- 能否能装满背包（或者最多装多少）：dp[j] = max(dp[j], dp[j - nums[i]] + nums[i])
   - [416. 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/)
   - [1049. 最后一块石头的重量 II](https://leetcode.cn/problems/last-stone-weight-ii/)
- 装满背包有几种方法：dp[j] += dp[j - nums[i]] 
   - [494. 目标和](https://leetcode.cn/problems/target-sum/)
   - [518. 零钱兑换 II](https://leetcode.cn/problems/coin-change-2/)
   - [377. 组合总和 Ⅳ](https://leetcode.cn/problems/combination-sum-iv/)
   - [70. 爬楼梯进阶版（完全背包）](https://programmercarl.com/0070.%E7%88%AC%E6%A5%BC%E6%A2%AF%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85%E7%89%88%E6%9C%AC.html)
- 背包装满最大价值：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]); 
   - [474. 一和零](https://leetcode.cn/problems/ones-and-zeroes/)
- 装满背包所有物品的最小个数：dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
   - [322.零钱兑换](https://programmercarl.com/0322.%E9%9B%B6%E9%92%B1%E5%85%91%E6%8D%A2.html)
   - [279.完全平方数](https://programmercarl.com/0279.%E5%AE%8C%E5%85%A8%E5%B9%B3%E6%96%B9%E6%95%B0.html)
   - [HJ16 购物单](https://www.nowcoder.com/practice/f9c6f980eeec43ef85be20755ddbeaf4?tpId=37&tqId=21239&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=)

### 遍历顺序（0-1 背包）
- 对于二维数组实现 0-1 背包，外层遍历物品和外层遍历背包容量都可以，内层遍历从小到大正序，因为当前的状态总是根据上一步状态来的，而二维数组下当前状态是空的。
- 当使用一维滚动数组实现 0-1 背包时，只能外层遍历物品，内层遍历背包容量，且从大到小遍历。
   - 从大到小倒序遍历，保证每个物品只被拿一次；本质还是二维数组的遍历，即右下角的值依赖上一层左上角的值，因此需要倒叙覆盖。
   - 如果外层容量内层物品，那么背包每个容量只会被放入一个物品（一维数组）。

### 遍历顺序（完全背包）
一维 dp 数组实现完全背包，外层遍历物品还是遍历背包都可以，但内层需要从小到大正序遍历。
- 求组和数，外层 for 遍历物品，内层 for 遍历背包。（物品在外面，后面的物品只会出现在前面物品的后面）
- 求排列数，外层 for 遍历背包，内层 for 遍历物品。

### 总结
![](https://code-thinking-1253855093.file.myqcloud.com/pics/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%981.jpeg)

## 打家劫舍系列
- 数组上连续元素二选一
- 成环后二选一。（不考虑首/尾，两次）
- 树上连续元素二选一
   - 后序遍历，暴力 + map 避免重复计算  
   - 动规（树形动规）

## 买卖股票系列
![](https://code-thinking.cdn.bcebos.com/pics/%E8%82%A1%E7%A5%A8%E9%97%AE%E9%A2%98%E6%80%BB%E7%BB%93.jpg)
- 一段时间只能买一次，最大收益
   - [121. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/)
   - 贪心：左取最小，右取最大
   - 动规
- T + 0 交易，当天买卖。
   - [122. 买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/)
   - 贪心，收集每天的正利润
   - 动规
- 最多完成 2 笔交易
   - [123. 买卖股票的最佳时机 III](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/)
   - 五种状态
- 最多完成 k 笔交易
   - [188. 买卖股票的最佳时机 IV](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/)
   - 2k + 1 种状态
- 含冷冻期
   - [309. 最佳买卖股票时机含冷冻期](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
   - 4 种状态，实际上 3 种就可以
- 含手续费
   - [714. 买卖股票的最佳时机含手续费](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)
   - 类似于 122, T+0，多一个手续费

## 子序列问题
### 非连续子序列
- dp[i]，[0,i] 中子序列问题定义
- 双层循环，外层遍历整个序列，内层遍历 j 当前 [0,i ) 子序列
- 额外变量 ans 记录结果（不一定需要）
- [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)

### 连续子序列
- dp[i]，以 i 结尾的连续子序列
- 循环， i 和 i - 1 比较
- 额外变量 ans 记录结果
- [674. 最长连续递增序列](https://leetcode.cn/problems/longest-continuous-increasing-subsequence/)
- [53. 最大子序和](https://leetcode.cn/problems/maximum-subarray/)

### 公共连续子序列
- dp[i][j]，i-1 结尾的 A，和 j - 1 结尾的 B 的公共问题定义
   - 定义 i-1 是为了与前一步比较时方便，i 可以从 1 开始，兼顾与上一步 i-1 的比较
- 双层循环，外层 A 遍历，内层 B 遍历
- [718. 最长重复子数组](https://leetcode.cn/problems/maximum-length-of-repeated-subarray/)
- [HJ75 公共子串计算](https://www.nowcoder.com/practice/98dc82c094e043ccb7e0570e5342dd1b?tpId=37&tqId=21298&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=)（进阶：空间复杂度 O(n)）

### 公共子序列（不要求连续）
- dp[i][j]：长度为[0, i - 1]的字符串 text1 与长度为 [0, j - 1] 的字符串text2的最长公共子序列为dp[i][j]
- 双层循环，外层 A 内层 B，可互换
- [1143.最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/)
- [1035. 不相交的线](https://leetcode.cn/problems/uncrossed-lines/)

## 编辑距离问题
### 非连续子序列匹配个数问题
- 问题描述：两个字符串s 和 t，计算 s 的子序列在 t 中出现的个数
- 如果是连续子序列，可以用 KMP，不要求连续，可以用动规
- dp[i][j]：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为dp[i][j]
- 考虑是否用 s[i - 1] 来匹配，类似于正则匹配时 * 匹配 0 次和 1 次的情况
- [115. 不同的子序列](https://leetcode.cn/problems/distinct-subsequences/)

### 两字符串删除字符后相等
- 当word1[i - 1] 与 word2[j - 1]相同的时候，不需要删除
- 当word1[i - 1] 与 word2[j - 1]不相同的时候
   - 删除 word1 中 i - 1
   - 删除 word2 中 j - 1
   - 同时删除

### 两个字符串，转换成相等最少需要操作数
- 相等，不操作
- 不相等
   - 增（实际上增和删可以理解为 1 个，A 的增相当于 B 的删）
   - 删
   - 换
- [HJ52 计算字符串的编辑距离](https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314?tpId=37&tqId=21275&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=)

## 回文串问题
### 回文子串
- 暴力：两层 for 循环,遍历起始终止，并判断是否回文 O(n^3)
- dp[i][j] ：[i,j] 是否是回文，bool，相比暴力，少一层判断是否是回文，O(n^2)
- [647. 回文子串](https://leetcode.cn/problems/palindromic-substrings/)

### 回文子序列
- 回文子串是连续的，回文子序列是不连续的
- dp[i][j] ：[i, j] 范围内最长回文子序列长度
- s[i] == s[j]
- s[i] != s[j]
   - 分别加入 s[i]，s[j]，取最值

# 字符串
## 常见输入操作
- getline(cin, string::s)
- cin >> noskipws，cin 不忽略空格

# REFERENCES
- [程序员Carl](https://github.com/youngyangyang04) 的 [代码随想录](https://www.programmercarl.com/)
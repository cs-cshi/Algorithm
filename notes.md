# 背包问题
![](https://img-blog.csdnimg.cn/20210117171307407.png)

## 动规五部曲：
1. 确定 dp 数组（dp table）以及下标的含义
2. 确定递推公式
3. dp 数组如何初始化
4. 确定遍历顺序
5. 举例推导 dp 数组

## 递推公式
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

## 遍历顺序
### 0-1 背包
- 对于二维数组实现 0-1 背包，外层遍历物品和外层遍历背包容量都可以，内层遍历从小到大正序，因为当前的状态总是根据上一步状态来的，而二维数组下当前状态是空的。
- 当使用一维滚动数组实现 0-1 背包时，只能外层遍历物品，内层遍历背包容量，且从大到小遍历。
   - 从大到小倒序遍历，保证每个物品只被拿一次；本质还是二维数组的遍历，即右下角的值依赖上一层左上角的值，因此需要倒叙覆盖。
   - 如果外层容量内层物品，那么背包每个容量只会被放入一个物品（一维数组）。

### 完全背包
一维 dp 数组实现完全背包，外层遍历物品还是遍历背包都可以，但内层需要从小到大正序遍历。
- 求组和数，外层 for 遍历物品，内层 for 遍历背包。（物品在外面，后面的物品只会出现在前面物品的后面）
- 求排列数，外层 for 遍历背包，内层 for 遍历物品。

## 总结
![](https://code-thinking-1253855093.file.myqcloud.com/pics/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%981.jpeg)


# REFERENCES
- [程序员Carl](https://github.com/youngyangyang04) 的 [代码随想录](https://www.programmercarl.com/)
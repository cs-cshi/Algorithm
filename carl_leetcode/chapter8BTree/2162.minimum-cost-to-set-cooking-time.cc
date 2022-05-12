/**
 * 2162. 设置时间的最少代价
 * 常见的微波炉可以设置加热时间，且加热时间满足以下条件：
 *    - 至少为 1 秒钟。
 *    - 至多为 99 分 99 秒。
 * 你可以 最多 输入 4 个数字 来设置加热时间。如果你输入的位数不足 4 位，微波炉会自动加 前缀 0 来补足 4 位。微波炉会将设置好的四位数中，前 两位当作分钟数，后 两位当作秒数。它们所表示的总时间就是加热时间。比方说：
 *    - 你输入 9 5 4 （三个数字），被自动补足为 0954 ，并表示 9 分 54 秒。
 *    - 你输入 0 0 0 8 （四个数字），表示 0 分 8 秒。
 *    - 你输入 8 0 9 0 ，表示 80 分 90 秒。
 *    - 你输入 8 1 3 0 ，表示 81 分 30 秒。
 * 给你整数 startAt ，moveCost ，pushCost 和 targetSeconds 。一开始，你的手指在数字 startAt 处。将手指移到 任何其他数字 ，需要花费 moveCost 的单位代价。每 输入你手指所在位置的数字一次，需要花费 pushCost 的单位代价。
 *
 * 要设置 targetSeconds 秒的加热时间，可能会有多种设置方法。你想要知道这些方法中，总代价最小为多少。
 *
 * 请你能返回设置 targetSeconds 秒钟加热时间需要花费的最少代价。
 *
 * 请记住，虽然微波炉的秒数最多可以设置到 99 秒，但一分钟等于 60 秒。
 *
 * 链接：https://leetcode.cn/problems/minimum-cost-to-set-cooking-time
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    /**
     * 1. 将 targetSeconds 转换成可能存在的输入方案
     *     - 第一种，严格按照秒不超过 60 的方式，但需要注意当分钟达到100时，此方案会变成五位数，不可取
     *     - 第二种，当秒小于 39 时，向分借1转换成大于 60秒的数
     */
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds)
    {
        vector<string> schemes;
        int seconds = targetSeconds % 60; // 秒
        int minutes = targetSeconds / 60; // 分钟

        // 方案一：分钟数小于 60 表示法
        if (minutes < 100)
        {
            if (minutes >= 1 && seconds < 10)
                schemes.push_back(to_string(minutes) + "0" + to_string(seconds));
            else if (minutes == 0)
                schemes.push_back(to_string(seconds));
            else
                schemes.push_back(to_string(minutes) + to_string(seconds));
        }

        // 方案二：秒钟数 >= 60，<= 99 表示法
        if (minutes >= 1 && seconds <= 39)
        {
            seconds += 60;
            minutes -= 1;
            if (minutes > 0)
                schemes.push_back(to_string(minutes) + to_string(seconds));
            else // 分钟为 0
                schemes.push_back(to_string(seconds));
        }

        int ans = INT_MAX;
        // 计算两种表示法的成本，若输入位小于 4 位，直接采用系统自动补全的方式，因为这必然会小于等于手动补全的成本
        for (int i = 0; i < schemes.size(); i++)
        {
            int curCost = 0;
            int curNum = startAt;
            for (int j = 0; j < schemes[i].size(); j++)
            {
                int num = schemes[i][j] - '0';
                if (num != curNum)  // 移动手指至其他数字
                {
                    curCost += moveCost;
                    curNum = num;
                }
                curCost += pushCost;    // 按下当前数字
            }
            ans = min(ans, curCost);
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    solution.minCostSetTime(1, 9403, 9402, 6008);
    return 0;
}
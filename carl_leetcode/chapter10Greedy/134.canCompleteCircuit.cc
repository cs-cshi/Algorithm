/**
 * 134. 加油站
 * 在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
 * 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
 * 给定两个整数数组 gas 和 cost ，如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。
 * 链接：https://leetcode-cn.com/problems/gas-station
 */

#include <vector>

using std::vector;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        for (int i = 0; i < gas.size(); i++)
        {
            int rest = gas[i] - cost[i];
            int index = (i + 1) % gas.size(); // 下一站
            while (rest >= 0 && index != i)
            {
                rest += gas[index] - cost[index];
                index = (i + 1) % gas.size();
            }
            if (rest > 0 || index == i)
                return i;
        }
        return -1;
    }

    int canCompleteCircuit2(vector<int> &gas, vector<int> &cost)
    {
        int curSum = 0;
        int min = __INT_MAX__;
        for (int i = 0; i < gas.size(); i++)
        {
            int rest = gas[i] - cost[i];
            curSum += rest;
            min = curSum < min ? curSum : min;
        }

        if (curSum < 0)
            return -1;

        if (min >= 0)
            return 0;

        for (int i = gas.size() - 1; i >= 0; i--)
        {
            int rest = cost[i] - gas[i];
            min += rest;
            if (min >= 0)
                return i;
        }
        return -1;
    }

    int canCompleteCircuit3(vector<int> &gas, vector<int> &cost)
    {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0)
            {
                curSum = 0;
                start = i + 1;
            }
        }
        if(totalSum < 0)
            return -1;
        return start;
    }
};
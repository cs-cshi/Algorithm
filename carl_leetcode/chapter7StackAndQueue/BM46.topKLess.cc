/**
 * BM46 最小的K个数
 * 给定一个长度为 n 的可能有重复值的数组，找出其中不去重的最小的 k 个数。例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4(任意顺序皆可)。
 * 数据范围：0 ≤ k,n ≤ 10000，数组中每个数的大小 0 ≤ val ≤ 1000
 * 要求：空间复杂度 O(n) ，时间复杂度 O(nlogn)
 */

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        sort(input.begin(), input.end());
        priority_queue<int, vector<int>, less<int>> pri_que;
        for (int i = 0; i < input.size(); i++)
            pri_que.push(input[i]);

        while (pri_que.size() > k)
            pri_que.pop();

        vector<int> ans(k); // 需初始化大小
        for (int i = k - 1; i >= 0; i--)
        {
            ans[i] = pri_que.top();
            pri_que.pop();
        }
        return ans;
    }
};
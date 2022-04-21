/**
 * 给你一个整数数组 nums 和一个整数 k，请你返回其中出现频率前 k 高的元素。你可以按任意顺序返回答案。
 * 链接：https://leetcode-cn.com/problems/top-k-frequent-elements/
 */

#include <vector>
#include <utility>
#include <unordered_map>
#include <queue>

using std::pair;
using std::priority_queue;
using std::unordered_map;
using std::vector;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map; // 统计 nums 中每个字符出现次数
        for (int i = 0; i < nums.size(); i++)
            map[nums[i]]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que; // 小根堆，按出现频次排序
        for (pair<int, int> iter : map)
            pri_que.push(iter);

        while (pri_que.size() > k) // 保证小根堆留下前 k 大的元素
            pri_que.pop();

        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--)
        {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }

private:
    class mycomparison
    {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            return lhs.second > rhs.second;
        }
    };
};

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> umap;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
        umap[nums[i++]]++;

    for (const pair<int, int> iter : umap)
    {
        if(iter.second >= k)
            ans.push_back(iter.first);
    }
    return ans;
}
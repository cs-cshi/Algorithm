/**
 * 332. 重新安排行程
 * 给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。
 * 所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。
 *      - 例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
 * 假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次
 * 链接：https://leetcode.cn/problems/reconstruct-itinerary
 */

#include <vector>
#include <string>
#include <unordered_map>
// #include <priority_queue>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // 存储每个机场能到达机票
    map<string, priority_queue<string, vector<string>, greater<string>>> vec;

    vector<string> ans;

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (const vector<string> &it : tickets)
            vec[it[0]].emplace(it[1]);
        
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }


    void dfs(const string &cur)
    {
        // 只有当前机场所有机票都走完才入栈
        while (vec.count(cur) && vec[cur].size() > 0)
        {
            string tmp = vec[cur].top();
            vec[cur].pop();
            dfs(move(tmp));
        }
        ans.emplace_back(cur);
    }
};
/**
 * 56. 合并区间
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 * 链接：https://leetcode-cn.com/problems/merge-intervals
 */

#include <vector>
#include <algorithm>

using std::max;
using std::min;
using std::sort;
using std::vector;

class Solution
{
private:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        if (intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b)
             { return a[0] < a[0]; });
        // sort(intervals.begin(), intervals.end(), cmp);
        vector<int> interval = {intervals[0][0], intervals[0][1]};
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i - 1][1] >= intervals[i][0])
            {
                interval[0] = min(interval[0], intervals[i][0]);
                interval[1] = max(interval[1], intervals[i][1]);
            }
            else
            {
                result.push_back(interval);
                interval.clear();
                interval = {intervals[i][0], intervals[i][1]};
            }
        }
        // if(intervals[intervals[intervals.size()-2][1] < intervals[intervals.size()-1][1])
        result.push_back(interval);
        return result;
    }
};
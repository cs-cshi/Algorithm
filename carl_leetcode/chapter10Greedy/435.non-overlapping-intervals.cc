/**
 * 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。
 * 链接：https://leetcode.cn/problems/non-overlapping-intervals
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 2)
            return 0;

        sort(intervals.begin(), intervals.end(), compare);
        int ans = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < intervals[i - 1][1])
            {
                ans++;
                intervals[i][1] = intervals[i - 1][1];
            }
        }
        return ans;
    }

private:
    // 按右界从小到大排序，然后从遍历左向右删除。从左向右遍历是按右界来比较的，删除大的下一个的空间选择就更大
    // 也可以按左界从小到大排序，然后遍历从右往左删除
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        if (a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }
};
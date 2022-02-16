/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
*/

#include <vector>
#include <algorithm>

using std::max;
using std::sort;
using std::vector;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size()==1)
        return intervals;

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (int i = 0; i < intervals.size(); i++)
    {
        int begin = intervals[i][0];  // 当前待合并区间的头
        int end = intervals[i][1];  //  当前待合并区间的尾

        // 第一个区间，或者区间无法合并
        // 先将区间加入到已合并区间，再更新区间的尾
        if (!ans.size() || ans.back()[1] < begin)  
            ans.push_back({begin, end});
        else  // 区间可以合并
            ans.back()[1] = max(end, ans.back()[1]);
    }

    return ans;
}

int main()
{
    return 0;
}
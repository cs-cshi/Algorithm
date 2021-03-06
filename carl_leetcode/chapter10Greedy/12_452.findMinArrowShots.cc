/**
 * 452. 用最少数量的箭引爆气球
 * 有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。
 * 一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。
 * 给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。
 * 链接：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons
 */

#include <vector>
#include <algorithm>

// using std::min;
// using std::sort;
// using std::vector;
using namespace std;

class Solution
{
private:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }

public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), cmp);
        int result = 1;
        for (int i = 0; i < points.size() - 1; i++)
        {
            if (points[i][1] < points[i + 1][0]) // 气球 i+1 和气球 i 没有挨着
                result++;
            else // 气球 i+1 和气球 i 挨着
                points[i + 1][1] = min(points[i][1], points[i + 1][1]);
        }
        return result;
    }

    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() < 2)
            return points.size();
        int ans = 1;
        sort(points.begin(), points.end(), compare);
        int left = points[0][0];
        int right = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > right)
            {
                ans++;
                left = points[i][0];
                right = points[i][1];
                continue;
            }
            left = max(left, points[i][0]);
            right = min(right, points[i][1]);
        }
        return ans;
    }
};
/*
给你一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间 intervals[i] = [starti, endi]，
为避免会议冲突，同时要考虑充分利用会议室资源，请你计算至少需要多少间会议室，才能满足这些会议安排。
*/
#include <vector>
#include <queue>
#include <algorithm>

using std::greater;
using std::priority_queue;
using std::sort;
using std::vector;

/*
整体思路：
1. 将时间安排数组 intervals 按照会议开始时间从小到大排序
2. 初始化一个新的最小堆，将第一个会议的结束时间加入到堆中。我们只需要记录会议的结束时间，告诉我们什么时候房间会空。
3. 对每个会议，检查堆的最小元素（即堆顶部的房间）是否空闲。
    - 若房间空闲，则从堆顶拿出该元素，将其改为我们处理的会议的结束时间，加回到堆中。
    - 若房间不空闲。开新房间，并加入到堆中。
4. 处理完所有会议后，堆的大小即为开的房间数量。这就是容纳这些会议需要的最小房间数。
*/

// intervals 按会议开始时间排序
static bool cmp1(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}

// intervals 按会议结束时间排序
static bool cmp2(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

// 优先队列法，最小堆
int minMeetingRooms(vector<vector<int>> &intervals)
{
    if (intervals.size() == 0 || intervals[0].size() == 0)
        return 0;

    sort(intervals.begin(), intervals.end(), cmp1);

    /*
    priority_queue<typename,container,functional>
        - typename：数据的类型
        - container：实现的容器类型，不能是 list，默认 vector
        - functional：比较方式，最大堆 less(<)，最小堆 greater(>)
    */
    priority_queue<int, vector<int>, greater<int>> occupied;

    for (auto meet : intervals)
    {
        if (!occupied.empty() && meet[0] >= occupied.top()) // 新的会议开始时间大于占用会议结束时间
            occupied.pop();
        occupied.push(meet[1]); // 将会议结束时间入堆
    }
    return occupied.size();
}

/*
1. 分别将开始时间和结束时间存进两个数组。
2. 分别对开始时间和结束时间进行排序。请注意，这将打乱开始时间和结束时间的原始对应关系。它们将被分别处理。
3. 考虑两个指针：s_ptr 和 e_ptr ，分别代表开始指针和结束指针。开始指针遍历每个会议，结束指针帮助我们跟踪会议是否结束。
4. 当考虑 s_ptr 指向的特定会议时，检查该开始时间是否大于 e_ptr 指向的会议。若如此，则说明 s_ptr 开始时，已经有会议结束。于是我们可以重用房间。否则，我们就需要开新房间。
5. 若有会议结束，换而言之，start[s_ptr] >= end[e_ptr] ，则自增 e_ptr 。
6. 重复这一过程，直到 s_ptr 处理完所有会议。
*/
int minMeetingRooms2(vector<vector<int>> &intervals)
{
    if (intervals.size() == 0 || intervals[0].size() == 0)
        return 0;

    auto intervals_end = vector<vector<int>>(intervals.begin(), intervals.end());

    sort(intervals.begin(), intervals.end(), cmp1);
    sort(intervals_end.begin(), intervals_end.end(), cmp2);

    int used_room = 0;
    int start_point = 0, end_point = 0;
    while(start_point < intervals.size())
    {
        if(intervals[start_point][0] >= intervals_end[end_point][1])
        {
            used_room--;
            end_point++;
        }
        used_room++;
        start_point++;
    }
    return used_room;
}
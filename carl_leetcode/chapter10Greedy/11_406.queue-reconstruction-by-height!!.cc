/**
 * 406. 根据身高重建队列
 * 假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
 * 请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
 * 链接：https://leetcode.cn/problems/queue-reconstruction-by-height
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    /**
     * 思想：
     * 1. 先按身高排序
     * 2. 再遍历排序后的数组，并将每个元素插入到 ki 对应索引的位置
     */
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        // sort(people.begin(), people.end(), compare);
        sort(people.begin(), people.end(), compare2);
        for (int i = 0; i < people.size(); i++)
        {
            vector<int> tmp = people[i];
            people.erase(people.begin() + i);
            people.insert(people.begin() + people[i][1], people[i]);
        }
        return people;
    }

private:
    // 按第二个数从小到大排序，第二个数相等情况按第一个数从大到小排序
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        if (a[1] < b[1])
            return true;
        else
        {
            if (a[1] == b[1] && a[0] > b[0])
            {
                return true;
            }
            else
                return false;
        }
    }

    // 按照第一个数从大到小排序，第一个数相同时，按第二个数从小到大排序
    static bool compare2(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
};
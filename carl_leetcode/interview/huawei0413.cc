/**
 * 华为面试题，分糖果
 * 将一堆糖果分给两个人，每袋糖果中的数量不完全一样，一袋只能分给一个人且所有糖果必须分完，两个人分到的糖果数量必须相同，请返回两个人分到的糖果数量，如无法平均分配返回 -1
 *
 * 输入: 第一行输入糖果袋数，取值范围[1,100];
 *       第二行输入整型数组，描述每袋糖果中糖果数量，取值范围[1,100]
 * 输出: 第一行平均分配的糖果数，如不能平均分为 -1
 *       第二、三行为两人分配的每袋糖果中的糖果数。
 *
 * 示例1：
 *          输入：2
 *                100 100
 *          输出：100
 *                100
 *                100
 * 示例2：
 *          输入：5
 *                7 4 5 3 3
 *          输出：11
 *                7 4
 *                5 3 3
 */

#include "bits/stdc++.h"

using namespace std;

// void backtracking(int len, vector<int> &cost, int startIndex, vector<int> &res1, vector<int> &path, int &curSum, int &target);
bool backtracking(int len, vector<int> &cost, int startIndex, vector<int> &res1, vector<int> &path, int &curSum, int &target);

// bool flag = false;
// bool flag2 = false;

void candy(int len, vector<int> &cost)
{
    vector<int> path;
    vector<int> res1;
    vector<int> res2;
    int target = 0;
    for (int item : cost)
        target += item;
    if (target % 2 == 1)
    {
        cout << -1;
        return;
    }
    target = target / 2;
    int curSum = 0;
    if (!backtracking(len, cost, 0, res1, path, curSum, target))
    {
        cout << -1;
        return;
    }

    for (int i = 0; i < cost.size(); i++)
        if (find(res1.begin(), res1.end(), i) == res1.end())
            res2.push_back(i);

    for (int i : res1)
        cout << cost[i] << " ";
    cout << endl;
    for (int i : res2)
        cout << cost[i] << " ";
}

/*
void backtracking(int len, vector<int> &cost, int startIndex, vector<int> &res1, vector<int> &path, int &curSum, int &target)
{
    if (curSum == target)
    {
        flag2 = true;
        if (flag == false)
            cout << curSum << endl;
        for (int i = 0; i < path.size(); i++)
            res1.push_back(path[i]);
        // cout << path[i];
        // if (i != path.size() - 1)
        //     cout << " ";
        // if (flag == false)
        // cout << endl;
        flag = true;
        return;
    }

    for (int i = startIndex; i < len; i++)
    {

        if (curSum + cost[i] <= target && !flag2)
        {
            curSum += cost[i];
            path.push_back(i);
            backtracking(len, cost, i + 1, res1, path, curSum, target);
            path.pop_back();
            curSum -= cost[i];
        }
        else
            continue;
    }
}
*/

bool backtracking(int len, vector<int> &cost, int startIndex, vector<int> &res1, vector<int> &path, int &curSum, int &target)
{
    if (curSum == target)
    {
        // if (flag == false)
        cout << curSum << endl;
        for (int i = 0; i < path.size(); i++)
            res1.push_back(path[i]);
        // flag = true;
        return true;
    }

    for (int i = startIndex; i < len; i++)
    {
        if (curSum + cost[i] <= target)
        {
            curSum += cost[i];
            path.push_back(i);
            if (backtracking(len, cost, i + 1, res1, path, curSum, target))
                return true;
            path.pop_back();
            curSum -= cost[i];
        }
    }
    return false;
}

int main()
{
    // int len;
    // cin >> len;
    // vector<int> vec;
    // while (len--)
    // {
    //     int a;
    //     cin >> a;
    //     vec.push_back(a);
    // }
    int len = 6;
    vector<int> vec = {1, 1, 1, 1, 1, 1};
    candy(len, vec);
}
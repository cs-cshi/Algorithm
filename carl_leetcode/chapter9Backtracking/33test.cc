#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void backtracking(vector<int> &candidates, vector<int> &cur, vector<bool> &used, vector<vector<int>> &ans, int target)
{
    if (cur.size() == 3 && cur[0] * cur[1] * cur[2] != target)
        return;
    else if (cur.size() == 6 && cur[3] * cur[4] * cur[5] != target)
        return;
    else if (cur.size() == 7 && (cur[0] * cur[3] * cur[6] != target || cur[2] * cur[4] * cur[6] == target))
        return;
    else if (cur.size() == 8 && cur[1] * cur[4] * cur[7] != target)
        return;
    else if (cur.size() == 9)
    {
        if (cur[2] * cur[5] * cur[8] != target || cur[0] * cur[4] * cur[8] != target)
            return;
        else
            ans.push_back(cur);
    }

    for (int i = 0; i < candidates.size(); i++)
    {
        if (used[i] == true)
            continue;
        used[i] = true;
        cur.push_back(candidates[i]);
        backtracking(candidates, cur, used, ans, target);
        cur.pop_back();
        used[i] = false;
    }
}

int main()
{
    vector<int> candidates = {1, 2, 4, 5, 10, 20, 25, 50, 100}; // 输入

    vector<vector<int>> ans; // 存储所有可能的结果
    long accumulation = 1;
    for (const auto num : candidates)
        accumulation *= num;

    int target = pow(accumulation, 1 / 3);

    vector<bool> used(9, false);
    vector<int> cur;
    backtracking(candidates, cur, used, ans, target);
    for (auto vec : ans)
    {
        for (auto num : vec)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}
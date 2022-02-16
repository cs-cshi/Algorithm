/*
给定一个无重复元素的正整数数组 candidates 和一个正整数 target ，找出 candidates 中所有可以使数字和为目标数 target 的唯一组合。

candidates 中的数字可以无限制重复被选取。如果至少一个所选数字数量不同，则两种组合是唯一的。 

对于给定的输入，保证和为 target 的唯一组合数少于 150 个。
*/
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void dfs(vector<int> &candidates, int target, vector<vector<int>> &answer, vector<int> &combine, int idx)
{
    // 递归退出条件:
    // 1. 已经比例完成数组  candidates
    if (idx == candidates.size())
        return;

    // 2. 当前combine 和 等于 target
    if (target == 0)
    {
        answer.emplace_back(combine);
        return;
    }

    // 对当前元素的处理两种可能

    // 2. 将当前元素加入 combine，作为可能为答案序列的一个元素
    // 条件：加入当前元素，总值不会超过 target
    if (target - candidates[idx] >= 0)
    {
        combine.emplace_back(candidates[idx]);
        dfs(candidates, target - candidates[idx], answer, combine, idx);
        combine.pop_back();
    }

    // 1. 直接跳过当前元素，不将其加入到 combine
    dfs(candidates, target, answer, combine, idx + 1);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> answer;
    vector<int> combine;
    dfs(candidates, target, answer, combine, 0);
    return answer;
}

int main()
{
    return 0;
}
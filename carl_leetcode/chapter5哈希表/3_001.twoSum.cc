/**
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那两个整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
 * 链接：https://leetcode-cn.com/problems/two-sum
 */

#include <vector>
#include <unordered_map>
#include <utility>

using std::pair;
using std::unordered_map;
using std::vector;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end())
                return {i, iter->second};
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }

    vector<int> twoSum2(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end())
                return {i, iter->second};
            map[nums[i]] = i;
        }
        return {};
    }
};
/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值 target 的那两个整数，
并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;

// 暴力破解，直接对数组循环两遍，每遍对应 twoSum 的一个数字。
vector<int> twoSum(const vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {0, 0};
}

// 利用 hash 表的特性，将寻找 twoSum 中另外一个数的时间复杂度降为 O(1)，遍历一遍。
// 利用 HashMap，键放数组中具体的值，值放索引。
// C++ 对应的 HashMap 是 unordered_map 容器。如果 find 方法没有找到对应的 key，返回 hashtablel.end()
vector<int> twoSumHash(const vector<int> &nums, int target)
{
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); i++)
    {
        if (hashtable.end() != hashtable.find(target - nums[i]))
            return {hashtable[target - nums[i]], i};
        hashtable[nums[i]] = i;
    }
    return {};
}

int main()
{
    // vector<int> nums = {2, 7, 11, 15};
    vector<int> nums = {3,3};
    int target = 6;

    vector<int> result = twoSum(nums, target);
    // cout << result << endl;
    for (auto iter : result)
        cout << iter << " ";
    cout << endl;

    result = twoSumHash(nums, target);
    // cout << result << endl;
    for (auto iter : result)
        cout << iter << " ";
    cout << endl;

    return 0;
}
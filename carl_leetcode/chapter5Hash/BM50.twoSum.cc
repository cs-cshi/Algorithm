/**
 * BM50 两数之和
 * 给出一个整型数组 numbers 和一个目标值 target，请在数组中找出两个加起来等于目标值的数的下标，
 * 返回的下标按升序排列。
 *（注：返回的数组下标从1开始算起，保证target一定可以由数组里面2个数字相加得到）
 */

#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        map<int, int> mymap;
        for (int i = 0; i < numbers.size(); i++)
        {
            auto iter = mymap.find(target - numbers[i]);
            if (iter != mymap.end())
            {
                if (i > iter->second)
                    return {iter->second + 1, i + 1};
                return {i + 1, iter->second + 1};
            }
            mymap[numbers[i]] = i;
        }
        return {};
    }
};
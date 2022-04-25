/**
 * BM54 三数之和
 * 给出一个有n个元素的数组S，S中是否有元素a,b,c满足a+b+c=0？找出数组S中所有满足条件的三元组。
 * 数据范围：0 ≤ n ≤ 3000，数组中各个元素值满足 ∣val∣≤ 100
 * 空间复杂度：O(n^2)
 * 时间复杂度：O(n^2)
 */

#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &num)
    {
        return useBacktracking(num);
    }

    vector<vector<int>> useHash(vector<int> &num)
    {
        vector<vector<int>> result;
        int len = num.size();

        if (num.size() < 3)
            return result;

        sort(num.begin(), num.end());

        // 第一个数遍历
        for (int i = 0; i < len; i++)
        {
            // 第一个数去重
            if (i != 0 && num[i] == num[i - 1])
                continue;

            if (num[i] > 0)
                break;

            unordered_set<int> set;

            // 第二个数遍历
            for (int j = i + 1; j < len; j++)
            {
                // 第三个数去重     可以把 set 中的数理解为第二个数，对于不满足 find target 的 num[j]都会入 set，找到的 target 可以理解为第三个数
                if (j > i + 2 && num[j] == num[j - 1] && num[j - 1] == num[j - 2])
                    continue;
                int target = 0 - num[i] - num[j];
                if (set.find(target) != set.end())
                {
                    result.push_back({num[i], num[j], target});
                    set.erase(target); // 第二个数去重
                }
                else
                    set.insert(num[j]);
            }
        }
        return result;
    }

    vector<vector<int>> useBinarySearch(vector<int> &num)
    {
        vector<vector<int>> result;
        int len = num.size();

        if (num.size() < 3)
            return result;

        sort(num.begin(), num.end());

        // 第一个数遍历
        for (int i = 0; i < len; i++)
        {
            // 第一个数去重
            if (i != 0 && num[i] == num[i - 1])
                continue;

            // 第二个数遍历
            for (int j = i + 1; j < len; j++)
            {
                // 第二个数去重
                if (j != i + 1 && num[j] == num[j - 1])
                    continue;
                int target = -(num[i] + num[j]);
                if (binarySearch(num, j + 1, len - 1, target))
                    result.push_back({num[i], num[j], target});
            }
        }
        return result;
    }

    bool binarySearch(vector<int> &num, int start, int end, int target)
    {
        while (start <= end)
        {
            int mid = ((end - start) >> 1) + start;
            if (num[mid] > target)
                end = mid - 1;
            else if (num[mid] < target)
                start = mid + 1;
            else
                return true;
        }
        return false;
    }

    /**
     * 局限，解集没有去重
     */
    vector<vector<int>> useBacktracking(vector<int> &num)
    {
        vector<int> path;
        vector<vector<int>> result;
        backtracking(num, path, result, 0, 0);
        for (auto resVec : result)
        {
            for (auto i : resVec)
                cout << i << " ";
            cout << endl;
        }
        return result;
    }

    void backtracking(vector<int> &num, vector<int> &path, vector<vector<int>> &result, int startIndex, int curSum)
    {
        /**
         * startIndex：避免初始化 curSum = 0 造成回溯直接结束
         * path.size()==3，确保是三个数之和
         *
         * */
        if (curSum == 0 && startIndex != 0 && path.size() == 3)
        {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < num.size(); i++)
        {
            if (path.size() < 3)
            {
                curSum += num[i];
                path.push_back(num[i]);
                backtracking(num, path, result, i + 1, curSum);
                path.pop_back();
                curSum -= num[i];
            }
        }
    }
};

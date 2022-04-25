/**
 * 给你一个二维整数数组 nums ，其中 nums[i] 是由 不同 正整数组成的一个非空数组，按 升序排列 返回一个数组，数组中的每个元素在 nums 所有数组 中都出现过。
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<vector<int>> &nums)
    {
        vector<int> ans;
        vector<int> pre(1001, 0);

        if (nums.size() == 1)
        {
            ans = nums[0];
            sort(ans.begin(), ans.end());
            return ans;
        }

        for (int j = 0; j < nums[0].size(); j++)
        {
            pre[nums[0][j]] = 1;
            // cout << nums[0][4] << endl;
            // cout << nums[0][j] << "  ";
        }

        for (int i = 1; i < nums.size(); i++)
        {
            vector<int> arr(1001, 0);
            for (int j = 0; j < nums[i].size(); j++)
            {
                if (pre[nums[i][j]] == 1)
                {
                    arr[nums[i][j]] = 1;
                    if (i == nums.size() - 1)
                        ans.push_back(nums[i][j]);
                }
            }
            pre = arr;
        }
        if (!ans.empty())
            sort(ans.begin(), ans.end());
        return ans;
    }
};
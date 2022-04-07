/**
 * 474. 一和零
 * 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
 * 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ones-and-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <algorithm>

using std::max;
using std::string;
using std::vector;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto str : strs)
        {
            int zeroNum = 0;
            int oneNum = 0;
            for (auto c : str)
            {
                if (c == '0')
                    zeroNum++;
                else
                    oneNum++;
            }

            for (int i = m; i >= zeroNum; i--)
            {
                for (int j = n; j >= oneNum; j--)
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
            }
        }
        return dp[m][n];
    }
};
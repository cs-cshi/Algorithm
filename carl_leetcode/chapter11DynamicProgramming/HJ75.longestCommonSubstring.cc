/**
 * HJ75 公共子串计算
 * 给定两个只包含小写字母的字符串，计算两个字符串的最大公共子串的长度。
 *   注：子串的定义指一个字符串删掉其部分前缀和后缀（也可以不删）后形成的字符串。
 *   数据范围：字符串长度：1\le s\le 150\1≤s≤150
 *   进阶：时间复杂度：O(n^3)，空间复杂度：O(n)
 * 输入描述：
 *      输入两个只包含小写字母的字符串
 * 输出描述：
 *      输出一个整数，代表最大公共子串的长度
 * 题目链接：https://www.nowcoder.com/practice/98dc82c094e043ccb7e0570e5342dd1b?tpId=37&tqId=21298&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 */
#include "bits/stdc++.h"

using namespace std;

int longestCommonSubstring(const string &str1, const string &str2)
{
    /**
     * 最长公共子序列
     * dp[i][j], [0, i-1] 与 [0, j-1] 最长公众子串
     * dp[i][j] = dp[i-1][j-1] + 1       if str1[i-1] == str2[j-1]
     * dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])            if str1[i-1] != str2[j-1]
     */

    /**
     * 最长公共子串
     * dp[i][j], 以 i-1 和 以 j-1] 结尾的最长公众子串
     * dp[i][j] = dp[i-1][j-1] + 1       if str1[i-1] == str2[j-1]
     * else = 0
     */

    /*    此段为正解，空间复杂度 O(n*m)，尝试 O(n)
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    int ans = 0;
    for(int i = 1; i <= str1.size(); i++) {
        for(int j = 1; j <= str2.size(); j++) {
            if(str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }
//     return dp[str1.size()][str2.size()];
    return ans;
    */

    // 用一维滚动数组思想
    vector<int> dp2(str2.size() + 1, 0);
    int ans2 = 0;
    for (int i = 1; i <= str1.size(); i++)
    {
        for (int j = str2.size(); j > 0; j--)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp2[j] = dp2[j - 1] + 1;
            }
            else
            {
                // dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                dp2[j] = 0;
            }
            ans2 = max(ans2, dp2[j]);
        }
    }
    return ans2;
}

int main()
{
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    int ans = longestCommonSubstring(str1, str2);
    cout << ans << endl;
    return 0;
}
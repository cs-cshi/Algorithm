/**
 * HJ16 购物单
 * 王强决定把年终奖用于购物，他把想买的物品分为两类：主件与附件，附件是从属于某个主件的，下表就是一些主件与附件的例子：
 * 如果要买归类为附件的物品，必须先买该附件所属的主件，且每件物品只能购买一次。
 * 每个主件可以有 0 个、 1 个或 2 个附件。附件不再有从属于自己的附件。
 * 王强查到了每件物品的价格（都是 10 元的整数倍），而他只有 N 元的预算。除此之外，他给每件物品规定了一个重要度，用整数 1 ~ 5 表示。他希望在花费不超过 N 元的前提下，使自己的满意度达到最大。
 * 满意度是指所购买的每件物品的价格与重要度的乘积的总和，假设设第ii件物品的价格为v[i]v[i]，重要度为w[i]w[i]，共选中了kk件物品，编号依次为j_1,j_2,...,j_kj
 * 链接：https://www.nowcoder.com/practice/f9c6f980eeec43ef85be20755ddbeaf4?tpId=37&tqId=21239&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 */

// 主件
// 主件 + 附件 1
// 主件 + 附件 2
// 主件 + 附件1 + 附件2

// dp[i][j], [0 - i] 的物品中任意选，放进容量为 j 的背包的最大满意度
// v[i]价格、w[i]重要度
// v[i][0,1,2] 价格， 0，主件，1第一个附件，2第二个附件
// w[j][0,1,2] 重要程度

#include <vector>
#include <iostream>

using namespace std;

// int getMaximumSatisfaction() {

// }

int main()
{
    // 没附件，1个附件，2个附件
    vector<vector<int>> v(60, vector<int>(3, 0)); // 价格
    vector<vector<int>> w(60, vector<int>(3, 0)); // 满意度
    int N;
    int m;
    cin >> N >> m;
    N /= 10; // 10 的倍数，统一除10，降低空间消耗

    // 组织数据
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a /= 10; // 10 的倍数，统一除10，降低空间消耗
        b *= a;  // 满意度
        if (c == 0)
        { // 主件
            v[i][0] = a;
            w[i][0] = b;
        }
        else
        {
            if (v[c][1] == 0)
            { // 主件的第一个附件
                v[c][1] = a;
                w[c][1] = b;
            }
            else
            { // 主件的第二个附件
                v[c][2] = a;
                w[c][2] = b;
            }
        }
    }

    vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0));

    // 0 - 1 背包
    // dp[i][j] = max(不放入，放入主，放入主 + 附1， 放入主 + 附2)
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int a = v[i][0];
            int b = w[i][0];
            int c = v[i][1];
            int d = w[i][1];
            int e = v[i][2];
            int f = w[i][2];
            // 主
            if (j >= a)
                dp[i][j] = max(dp[i - 1][j - a] + b, dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];

            // 主 + 附1
            if (j >= a + c)
                dp[i][j] = max(dp[i - 1][j - a - c] + b + d, dp[i][j]);

            // 主 + 附2
            if (j >= a + e)
                dp[i][j] = max(dp[i - 1][j - a - e] + b + f, dp[i][j]);

            if (j >= a + c + e)
                dp[i][j] = max(dp[i - 1][j - a - c - e] + b + d + f, dp[i][j]);
            //             cout << dp[i][j] << ' ';
        }
        //         cout << endl;
    }
    cout << dp[m][N] * 10 << endl;
    return 0;
}

/**
 * 738. 单调递增的数字
 * 当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。
 * 给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。
 * 链接：https://leetcode-cn.com/problems/monotone-increasing-digits
 */

#include <vector>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::stoi;
using std::string;
using std::to_string;
using std::vector;

class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string strNum = to_string(n);
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--)
        {
            if (strNum[i - 1] > strNum[i])
            {
                flag = i;
                strNum[i - 1]--;
            }
        }

        for (int i = flag; i < strNum.size(); i++)
            strNum[i] = '9';

        return stoi(strNum);
    }
};

int main()
{
    Solution solution;
    int result = solution.monotoneIncreasingDigits(1234);
    cout << result << endl;
}
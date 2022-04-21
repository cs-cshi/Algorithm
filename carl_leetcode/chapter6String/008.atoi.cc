/**
 * 8. 字符串转换整数 (atoi)
 * 请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。
 * 函数 myAtoi(string s) 的算法如下：
 *      读入字符串并丢弃无用的前导空格
 *      检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
 *      读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
 *      将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
 *      如果整数数超过 32 位有符号整数范围 [−2^31,  2^31 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
 *      返回整数作为最终结果。
 */

#include <string>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        if (s.size() == 0)
            return 0;
        string str = s;
        bool isPositive = true; // 判断正负，正数 true
        bool overflow = false;

        // 1. 处理前导空格
        int i = 0;
        int startIndex = 0;
        while (str[i] == ' ')
            i++;
        // str.substr(i, str.size());
        // cout << i << endl;

        // 2. 判断正负
        if (str[i] == '-')
        {
            isPositive = false;
            i++;
        }
        else if (str[i] == '+')
            i++;

        startIndex = i;
        // cout << i << endl;
        // 3. 读入下一个字符，直至结尾或非数字字符
        while (i < str.size() && str[i] >= '0' && str[i] <= '9')
            i++;

        str = str.substr(startIndex, i - startIndex);
        // cout << str << endl;
        // cout << str.size() << endl;

        // 4. 将数字字符串转换成整数
        long ans = 0;
        for (int j = 0; j < str.size(); j++)
        {
            // cout << str[j] - '0';
            ans = (str[j] - '0') + ans * 10;

            //  有可能字符串是 -INT32_MAX，若没有越界，不能返回 INT32_MIN
            if (ans > INT32_MAX)
            {
                ans = INT32_MAX;
                overflow = true;
                break;
            }
        }

        // cout << INT32_MAX << endl;
        // cout << INT32_MIN << endl;

        // 5. 边界判定
        if (isPositive == false)
        {
            if (overflow && ans == INT32_MAX)
                ans = INT32_MIN;
            else
                ans *= -1;
        }

        // 6. 返回结果
        return int(ans);
    }
};
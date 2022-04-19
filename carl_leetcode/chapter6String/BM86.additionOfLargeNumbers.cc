/**
 * BM86 大数加法
 * 以字符串的形式读入两个数字，编写一个函数计算它们的和，以字符串形式返回。
 */

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t)
    {
        // write code here
        int len1 = s.length(); // 长度，不是索引
        int len2 = t.length();

        if (len1 == 0)
            return t;
        if (len2 == 0)
            return s;

        int len = max(len1, len2); // ans 长度为最长字符串+1，多的一个用来存储结束符'\0'
        char ans[len + 1];
        ans[len] = '\0'; // 字符串以 '\0' 结尾
        int carry = 0;
        // 公共长度相加处理
        while (len1 && len2)
        {
            int tmp = (s[len1 - 1] - '0') + (t[len2 - 1] - '0') + carry;
            if (tmp >= 10)      // 进位
            {
                carry = 1;
                tmp = tmp % 10;
            }
            else
                carry = 0;
            ans[len - 1] = tmp + '0';
            //             cout << tmp + '0' << "  ";
            // cout << ans[len - 1];
            len--;
            len1--;
            len2--;
        }

        // t 短 s 长
        while (len1)
        {
            // cout << 1111 << endl;
            if (carry == 0)
                ans[len - 1] = s[len1 - 1];
            else
            {
                int tmp = s[len1 - 1] - '0' + carry;
                if (tmp >= 10)
                {
                    carry = 1;
                    tmp = tmp % 10;
                }
                else
                    carry = 0;
                ans[len - 1] = tmp + '0';
            }
            //             cout << ans[len-1];
            len1--;
            len--;
        }

        // t 长 s 短
        while (len2)
        {
            // cout << "222" << endl;
            // cout << t[len2 - 1] << endl;
            // cout << carry << endl;
            if (carry == 0)
                ans[len - 1] = t[len2 - 1];
            else
            {
                int tmp = t[len2 - 1] - '0' + carry;
                // cout << tmp << endl;
                if (tmp >= 10)
                {
                    carry = 1;
                    tmp = tmp % 10;
                }
                else
                    carry = 0;
                // cout << tmp << endl;
                ans[len - 1] = tmp + '0';
            }
            //             cout << len;
            // cout << ans[len - 1];

            len2--;
            len--;
        }

        // for (char c : ans)
        //     cout << c << ' ';

        if (carry)
            return "1" + string(ans);
        return string(ans);
    }
};
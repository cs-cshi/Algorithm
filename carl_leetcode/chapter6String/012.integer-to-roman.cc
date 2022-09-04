/**
 * 12. 整数转罗马数字
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 *   I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 *   X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 *   C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 * 给你一个整数，将其转为罗马数字。

链接：https://leetcode.cn/problems/integer-to-roman
*/

#include <string>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string ans;
        for (const auto &[x, str] : myPair)
        { // pair 数组遍历方法
            int count = num / x;
            if (count > 0)
            {
                while (count--)
                    ans += str;
                num %= x;
            }
        }
        return ans;
    }

    string intToRoman2(int num)
    {
        // if(num < 1)
        //     return itos(num);
        string ans;
        int x;
        if (num >= 1000)
        {
            x = num / 1000;
            num %= 1000;
            while (x--)
                ans += "M";
        }

        if (num >= 900)
        {
            x = num / 900;
            num %= 900;
            while (x--)
                ans += "CM";
        }

        if (num >= 500)
        {
            x = num / 500;
            num %= 500;
            while (x--)
                ans += "D";
        }

        if (num >= 400)
        {
            x = num / 400;
            num %= 400;
            while (x--)
                ans += "CD";
        }

        if (num >= 100)
        {
            x = num / 100;
            num %= 100;
            while (x--)
                ans += "C";
        }

        if (num >= 90)
        {
            x = num / 90;
            num %= 90;
            while (x--)
                ans += "XC";
        }

        if (num >= 50)
        {
            x = num / 50;
            num %= 50;
            while (x--)
                ans += "L";
        }

        if (num >= 40)
        {
            x = num / 40;
            num %= 40;
            while (x--)
                ans += "XL";
        }

        if (num >= 10)
        {
            x = num / 10;
            num %= 10;
            while (x--)
                ans += "X";
        }

        if (num >= 9)
        {
            x = num / 9;
            num %= 9;
            while (x--)
                ans += "IX";
        }

        if (num >= 5)
        {
            x = num / 5;
            num %= 5;
            while (x--)
                ans += "V";
        }

        if (num >= 4)
        {
            x = num / 4;
            num %= 4;
            while (x--)
                ans += "IV";
        }

        if (num >= 1)
        {
            while (num--)
                ans += "I";
        }

        return ans;
    }

private:
    // in-class 数组需指定大小，不能推断
    const pair<int, string> myPair[13] = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
};
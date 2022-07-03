/**
 * HJ92 在字符串中找出连续最长的数字串
 * 输入一个字符串，返回其最长的数字子串，以及其长度。若有多个最长的数字子串，则将它们全部输出（按原字符串的相对位置）。本题含有多组样例输入。
 * 数据范围：字符串长度 1≤n≤200，保证每组输入都至少含有一个数字
 * 输入一个字符串。1<=len(字符串)<=200
 * 输出描述：
 * 输出字符串中最长的数字字符串和它的长度，中间用逗号间隔。如果有相同长度的串，则要一块儿输出（中间不要输出空格）。
 * 题目链接：https://www.nowcoder.com/practice/2c81f88ecd5a4cc395b5308a99afbbec?tpId=37&tqId=21315&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> longestNumericString(const string &str)
{
    vector<int> ans;
    bool flag = false; // 标识是否进入数字子串区间
    int start = 0;
    int end = 0;
    int len = -1;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9' && !flag)
        { // 数字子串开头
            start = i;
            flag = true;
        }

        if ((str[i] < '0' || str[i] > '9') && flag)
        { // 遇到字母，且前面是数字子串
            end = i - 1;
            flag = false;
            //             cout << i << "..." << start << "..." << end << endl;
            if (end - start + 1 > len)
            {
                len = end - start + 1;
                ans.clear();
                ans.push_back(start);
                ans.push_back(end);
            }
            else if (end - start + 1 == len)
            {
                ans.push_back(start);
                ans.push_back(end);
            }
        }

        if (i == str.size() - 1 && str[i] >= '0' && str[i] <= '9' && flag)
        { // str 以数字结尾
            end = i;
            if (end - start + 1 > len)
            {
                ans.clear();
                ans.push_back(start);
                ans.push_back(end);
            }
            else if (end - start + 1 == len)
            {
                ans.push_back(start);
                ans.push_back(end);
            }
            //             cout << i << "..." << start << "..." << end << endl;
            flag = false;
            break;
        }
        //         cout << ans.size() << "!!!" << endl;
    }
    return ans;
}

int main()
{
    string s;
    while (getline(cin, s))
    {
        //         cout << s << " .... 1"<< endl;    // 输入没问题
        vector<int> ans;
        ans = longestNumericString(s);
        //         cout << 1111 << ans.size() << endl;
        if (ans.size() == 0)
            continue;
        for (int i = 0; i < ans.size(); i += 2)
        {
            int start = ans[i];
            int end = ans[i + 1];
            for (int j = start; j <= end; j++)
                cout << s[j];
        }
        cout << ',';
        cout << ans[1] - ans[0] + 1 << endl;
    }
    return 0;
}
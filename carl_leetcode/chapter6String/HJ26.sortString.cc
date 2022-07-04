/**
 * HJ26 字符串排序
 * 将输入字符串中的字符按如下规则排序。
 *      规则 1 ：英文字母从 A 到 Z 排列，不区分大小写。
 *          如，输入： Type 输出： epTy
 *      规则 2 ：同一个英文字母的大小写同时存在时，按照输入顺序排列。
 *          如，输入： BabA 输出： aABb
 *      规则 3 ：非英文字母的其它字符保持原来的位置。
 *          如，输入： By?e 输出： Be?y
 * 链接：https://www.nowcoder.com/practice/5190a1db6f4f4ddb92fd9c365c944584?tpId=37&tqId=21249&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * 思路：
 * 1. 对 str 中大小写字母，忽略大小写按字母顺序排序（稳定），并存入 vector 容器
 * 2. 同时遍历 str 和 vec。（注意：此时 str 中字母全部已经按要求存储在了 vector 容器中）
 *      - 若 str[i] 为字母，str[i] 赋值为 vec[k]，k++
 *      - 若 str[i] 为非字母， i++，保持原来字符，k 不变
*/
string sortString(string str)
{
    //     cout << str << endl;
    vector<char> vec;
    int len = str.size();

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (str[j] - 'a' == i || str[j] - 'A' == i)
                vec.push_back(str[j]);
        }
    }

    for (int i = 0, k = 0; i < len && k < vec.size(); i++)
    {
        if (islower(str[i]) || isupper(str[i]))
        {
            str[i] = vec[k++];
            //             cout << str[i];
        }
    }
    return str;
}

int main()
{
    string str;
    //     cin >> noskipws;
    while (getline(cin, str))
    {
        cout << sortString(str) << endl;
    }
    return 0;
}
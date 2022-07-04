/**
 * HJ17 坐标移动
 * 开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。从（0,0）点开始移动，从输入字符串里面读取一些坐标，并将最终输入结果输出到输出文件里面。
 * 合法坐标为A(或者D或者W或者S) + 数字（两位以内），坐标之间以;分隔。
 * 非法坐标点需要进行丢弃。如AA10;  A1A;  $%$;  YAD; 等。
 * 链接：https://www.nowcoder.com/practice/119bcca3befb405fbe58abe9c532eb29?tpId=37&tqId=21240&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 判断当前串是否是有效移动
bool isValid(const string &s)
{
    //     cout << "111" << endl;    // 过
    if (s.size() < 2 || s.size() > 3)
        return false;
    //     cout << s << endl;
    //     cout << "222" << endl;       // 过

    if (!(s[0] == 'A' || s[0] == 'S' || s[0] == 'W' || s[0] == 'D'))
        return false;

    //     cout << "333" << endl;       // 过

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    //     cout << "444" << endl;       // 过

    return true;
}

vector<int> moveTool(string &s)
{
    int start = 0;
    int end = 0;

    size_t pos = s.find(";");
    while (pos != s.npos)
    {
        string temp = s.substr(0, pos);
        //         cout << temp << "  " << endl;    // 没问题
        s = s.substr(pos + 1, s.size());
        pos = s.find(";");
        if (isValid(temp))
        {
            //             cout << "!!!!" << endl;
            char c = temp[0];
            //             cout << c << "  : ";
            int num = stoi(temp.substr(1, temp.size()));
            //             cout << num << endl;
            switch (c)
            {
            case 'A':
                start -= num;
                break;
            case 'S':
                end -= num;
                break;
            case 'W':
                end += num;
                break;
            case 'D':
                start += num;
                break;
            default:
                cout << "error ~" << endl;
            }
        }
    }
    vector<int> ans = {start, end};
    return ans;
}

int main()
{
    string str;
    while (getline(cin, str))
    {
        vector<int> ans;
        ans = moveTool(str);
        cout << ans[0] << ',' << ans[1] << endl;
    }
    return 0;
}
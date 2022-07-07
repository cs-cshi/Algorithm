/**
 * HJ27 查找兄弟单词
 * 定义一个单词的“兄弟单词”为：交换该单词字母顺序（注：可以交换任意次），而不添加、删除、修改原有的字母就能生成的单词。兄弟单词要求和原来的单词不同。例如： ab 和 ba 是兄弟单词。 ab 和 ab 则不是兄弟单词。现在给定你 n 个单词，另外再给你一个单词 x ，让你寻找 x 的兄弟单词里，按字典序排列后的第 k 个单词是什么？注意：字典中可能有重复单词。
 * 链接：https://www.nowcoder.com/practice/03ba8aeeef73400ca7a37a5f3370fe68?tpId=37&tqId=21250&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 */

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * 字典顺序
 */
static bool cmp(const string &str1, const string &str2)
{
    //     int i = 0, j = 0;
    //     for(int i = 0, j = 0; i < str1.size() && j < str2.size(); i++, j++) {
    //         if(str1[i] == str2[j])
    //             continue;
    //         else
    //             return str1[i] > str2[j];
    //     }
    return str1 < str2;
}

void searchBrotherWord(vector<string> &vecStr, string &word, int k)
{
    vector<int> vecChar(26);
    for (int i = 0; i < word.size(); i++)
        vecChar[word[i] - 'a']++;

    vector<string> broVec;

    for (const string str : vecStr)
    {
        if (str == word)
            continue;
        if (str.size() != word.size())
            continue;

        bool flag = true; // 当前 str 是否是兄弟单词

        vector<int> vecChar2(vecChar.begin(), vecChar.end());
        //         for(const char c : str) {
        //             vecChar2[c - 'a']--;
        //         }

        // 当前单词出现次数
        for (int i = 0; i < str.size(); i++)
        {
            vecChar2[str[i] - 'a']--;
            //             cout << vecChar2[str[i]] - 1;
        }

        // 验证当前 str 是否是兄弟单词
        for (int i = 0; i < vecChar2.size(); i++)
            if (vecChar2[i] != 0)
            {
                flag = false;
                break;
            }

        if (flag)
            broVec.push_back(str);
        //         cout << str << endl;
    }

    sort(broVec.begin(), broVec.end(), cmp);
    if (k <= broVec.size())
    {
        cout << broVec.size() << endl;
        cout << broVec[k - 1] << endl;
    }
    else
        cout << broVec.size() << endl;
}

int main()
{
    int len;
    cin >> len;
    //     cout <<  "len:" << len << endl;
    vector<string> vecStr;
    string str;
    while (len--)
    {
        cin >> str;
        vecStr.push_back(str);
    }
    string word;
    cin >> word;
    //     cout << "word:" << word << endl;
    int k;
    cin >> k;
    //     cout << "k:" << k << endl;
    //     cout << 111 << endl;
    searchBrotherWord(vecStr, word, k);

    return 0;
}
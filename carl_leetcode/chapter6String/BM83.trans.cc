/**
 * BM83 字符串变形
 * 输入描述：
 * 给定一个字符串s以及它的长度n(1 ≤ n ≤ 10^6)
 * 返回值描述：
 * 请返回变形后的字符串。题目保证给定的字符串均由大小写字母和空格构成。
 * 链接：https://www.nowcoder.com/practice/c3120c1c1bc44ad986259c0cf0f0b80e?tpId=295&tqId=44664&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj%3Ftab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295
 */

#include <string>
#include <algorithm>

using std::string;
using std::swap;

class Solution
{
public:
    string trans(string s, int n)
    {
        // deleteExtraSpace(s, n);   // 题目没要去删除冗余空格
        reverseUpperAndLower(s);
        reverse(s, 0, s.size());
        reverseWords(s);
        return s;
    }

    void reverseUpperAndLower(string &s)
    {
        for (int i = 0; i < s.size(); i++)
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 32;
            else if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
    }

    void reverseWords2(string &s)
    {
        int i = 0;
        while (i < s.size())
        {
            while (i < s.size() && s[i] == ' ')
            {
                i++;
            }
            int begin = i;
            while (i < s.size() && s[i] != ' ')
            {
                i++;
            }
            int en = i;
            reverse(s, begin, en);
        }
    }

    void reverseWords(string &s)
    {
        int wordStart = 0;
        int wordEnd = 0;
        bool flag = false;

        for (int i = 0; i < s.size(); i++)
        {
            // while()
            // 单词开始
            if (!flag || (s[i] != ' ' && s[i - 1] == ' '))
            {
                flag = true;
                wordStart = i;
            }

            // 单词后面有空格，单词结束
            if (flag && s[i] == ' ')
            {
                reverse(s, wordStart, i);
                flag = false;
            }

            if (flag && i == s.size() - 1)
            {
                reverse(s, wordStart, i + 1);
            }
        }
    }

    void reverse(string &s, int start, int end)
    {
        while (start < end)
            swap(s[start++], s[--end]);
    }

    void deleteExtraSpace(string &s, int n)
    {
        int slow = 0;
        int fast = 0;

        // 删除头部空格
        while (fast < n && s[fast] == ' ')
            fast++;

        // 删除连续两个空格的冗余空格
        while (fast >= 0 && fast < n)
        {
            // 连续两个空格
            if (s[fast] == ' ' && s[fast] == s[fast - 1])
                fast++;
            else
                s[slow++] = s[fast++];
        }

        // 删除尾部一个空格
        if (s[slow] == ' ')
            s.resize(slow - 1);
        else
            s.resize(slow);
    }
};
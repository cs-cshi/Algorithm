/**
 * 给你一个字符串 s ，逐个翻转字符串中的所有 单词 。
 * 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
 * 请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。
 * 说明：
 *      输入字符串 s 可以在前面、后面或者单词间包含多余的空格。
 *      翻转后单词间应当仅用一个空格分隔。
 *      翻转后的字符串中不应包含额外的空格。
 */
#include <string>
#include <algorithm>

using std::string;
using std::swap;

class Solution
{
public:
    void reverse(string &s, int start, int end) // [start, end]，索引
    {
        for (int i = start, j = end; i < j; i++, j--)
            swap(s[i], s[j]);
    }

    void removeExtraSpace(string &s)
    {
        int slowIndex = 0;
        int fastIndex = 0;
        // 删除字符串头冗余空格
        while (fastIndex < s.size() && s[fastIndex] == ' ') // 将 fastIndex 指针定位到第一个不为空格的字符处
            fastIndex++;

        // 删除字符串中间冗余空格
        for (; fastIndex < s.size(); ++fastIndex) // 快慢指针删除字符串中间冗余空格
        {
            if (fastIndex > 1 && s[fastIndex - 1] == s[fastIndex] && s[fastIndex] == ' ') // 如果 fastIndex 指针处是要删除的冗余空格，fastIndex 向后移
                continue;
            else
                s[slowIndex++] = s[fastIndex]; // 将 fastIndex 元素交换至 slowIndex 处
        }

        // 删除字符串尾冗余空格
        // 删除中间冗余空格时只会删除连续两个及以上空格的情况，一个是不会删除的，但尾部一个空格也是冗余的
        if (slowIndex > 0 && s[slowIndex - 1] == ' ')
            s.resize(slowIndex - 1);
        else
            s.resize(slowIndex);
    }

    string reverseWords(string s)
    {
        removeExtraSpace(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        int end = 0;
        bool entry = false; // 标识是否进入某个单词
        for (int i = 0; i < s.size(); i++)
        {
            // 单词开始
            if (!entry || (s[i] != ' ' && s[i - 1] == ' '))
            {
                start = i;
                entry = true;
            }

            // 单词后面有空格，空格就是单词分隔符
            if (entry && s[i] == ' ')
            {
                end = i - 1;
                reverse(s, start, end);
                entry = false;
            }

            // 字符串最后一个单词，结尾不是以空格，而是到达字符串的尾端
            if (entry && i == (s.size() - 1) && s[i] != ' ')
            {
                end = i;
                reverse(s, start, end);
            }
        }
    }

    void reverse2(string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
            swap(s[i], s[j]);
    }

    void removeExtraSpace2(string &s)
    {
        int fastIndex = 0;
        int slowIndex = 0;
        // 头部去除空格
        while (fastIndex < s.size() && s[fastIndex] == ' ')
            fastIndex++;

        // 中间去除冗余空格，连续两个都为空格为冗余
        while (fastIndex < s.size())
        {
            if (fastIndex > 1 && s[fastIndex] == ' ' && s[fastIndex] == s[fastIndex - 1])
                fastIndex++;
            else
                s[slowIndex++] = s[fastIndex++];
        }

        // 尾部去除空格
        if (slowIndex > 0 && s[slowIndex - 1] == ' ')
            s.resize(slowIndex - 1);
        else
            s.resize(slowIndex);
    }

    string reverseWords2(string s)
    {
        removeExtraSpace2(s);
        reverse2(s, 0, s.size() - 1);
        bool flag = false;
        int wordStart = 0;
        int wordEnd = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // 开始进入某个单词
            if (!flag || (s[i] != ' ' && s[i - 1] == ' '))
            {
                wordStart = i;
                flag = true;
            }
            // 遇到空格，单词分隔符
            if (flag && s[i] == ' ')
            {
                wordEnd = i - 1;
                reverse2(s, wordStart, wordEnd);
                flag = false;
            }

            // 最后一个单词
            if (flag && i == s.size() - 1)
            {
                wordEnd = i;
                reverse2(s, wordStart, wordEnd);
            }
        }
        return s;
    }

    string reverseWords(string s)
    {
        int slow = 0;
        int fast = 0;
        while (fast < s.size() && s[fast] == ' ')
            fast++;

        while (fast < s.size())
        {
            if (fast > 1 && s[fast] == ' ' && s[fast] == s[fast - 1])
                fast++;
            else
                s[slow++] = s[fast++];
        }

        if (slow > 0 && s[slow - 1] == ' ')
            s.resize(slow - 1);
        else
            s.resize(slow);
        reverse(s, 0, s.size() - 1);
        bool flag = false;
        int start = 0;
        int end;
        for (int i = 0; i < s.size(); i++)
        {
            if (flag == false)
            {
                start = i;
                flag = true;
            }

            if (flag && s[i] == ' ')
            {
                end = i - 1;
                flag = false;
                reverse(s, start, end);
            }

            if (i == s.size() - 1 && flag)
            {
                reverse(s,start,s.size()-1);
            }
        }
        return s;
    }
};
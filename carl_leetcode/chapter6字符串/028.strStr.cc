#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Solution
{
public:
    // 前缀表统一减一代码实现
    void getNext(int *next, const string &s)
    {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++)
        {
            while (j >= 0 && s[i] != s[j + 1]) // 前后缀不相同，回退
                j = next[j];

            if (s[i] == s[j + 1]) // 相同前后缀
                j++;

            next[i] = j; // 将前缀长度 j 赋值给 next[i]
        }
    }

    /**
     * haystack:文本串
     * needle：模式串
     */
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
            return 0;
        int next[needle.size()];
        getNext(next, needle);
        int j = -1;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j >= 0 && haystack[i] != needle[j + 1]) // 不匹配， needle 坐标需 +1，因为 j 从 -1 开始，表示的是当前匹配成功的模式串中最后一个字符位置，j+1表示下一个需要判断的位置
                j = next[j];

            if (haystack[i] == needle[j + 1]) // 匹配
                j++;

            if (j == (needle.size() - 1)) // 模式串最后一个字符匹配
                return (i - needle.size() + 1);
        }
        return -1;
    }
};

class Solution2
{
public:
    void getNext(int *next, const string &s)
    {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); i++)
        {
            while (j >= 1 && s[i] != s[j])
                j = next[j - 1];

            if (s[i] == s[j])
                j++;

            next[i] = j;
        }
    }

    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
            return 0;

        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j >= 1 && (haystack[i] != needle[j]))
                j = next[j - 1];

            if (haystack[i] == needle[j])
                j++;

            if (j == needle.size())
                return (i - needle.size() + 1);
        }
        return -1;
    }
};

int main()
{
    Solution *solution = new Solution();
    string haystack = "aaaaa";
    string needle = "bba";
    int result = solution->strStr(haystack, needle);
    cout << result << endl;
}
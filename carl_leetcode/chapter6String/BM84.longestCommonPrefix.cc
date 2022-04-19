/**
 * BM84 最长公共前缀
 * 给你一个大小为 n 的字符串数组 strs ，其中包含n个字符串 , 编写一个函数来查找字符串数组中的最长公共前缀，返回这个公共前缀。
 * 链接：https://www.nowcoder.com/practice/28eb3175488f4434a4a6207f6f484f47?tpId=295&tqId=732&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj%3Ftab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295
 */

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    /**
     *
     * @param strs string字符串vector
     * @return string字符串
     */
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";

        string ans = strs[0];
        if (strs.size() == 1)
            return ans;

        int last_j;
        for (int i = 1; i < strs.size(); i++)
        {
            int j = 0, k = 0;
            while (j < ans.size() && k < strs[i].size() && ans[j] == strs[i][k])
            {
                j++;
                k++;
            }
            last_j = j;
        }

        if (last_j == 0)
            return "";

        return ans.substr(0, last_j);
    }
};
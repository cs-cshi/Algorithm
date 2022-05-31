/**
 * 763. 划分字母区间
 * 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。
 * 链接：https://leetcode.cn/problems/partition-labels/
 */

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    /**
     * 1. 找出每个字符最右边界
     * 2. 遍历字符串 s, 并记录下当前窗口的最右界，如果遍历索引 i 等于最右界，说明当前窗口封闭，进入下一个窗口
     * 3. 将窗口最右界清除，最左界为下一个元素对应的索引位置，重复 1~3
     */
    vector<int> partitionLabels(string s)
    {
        vector<int> vec(26, 0);
        vector<int> ans;
        for (int i = 0; i < s.size(); i++)
        {
            vec[s[i] - 'a'] = i; // 记录下字符 s[i] 出现的最右的位置
        }

        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++)
        {
            right = max(right, vec[s[i] - 'a']);
            if (i == right)
            {
                ans.push_back(right - left + 1);
                left = right + 1;
                right = 0;
            }
        }
        return ans;
    }
};
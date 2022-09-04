/**
 * 14. 最长公共前缀
 * 编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。
 * https://leetcode.cn/problems/longest-common-prefix/
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 纵向比较
    // 两两横向比较，每次求出最长子串
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;  // 横
        int n = strs.size();
        bool flag = true;
        while(i < strs[0].size()) {
            char base = strs[0][i];
            for(int j = 0; j < n; j++) {    // 纵
                if(i >= strs[j].size() || strs[j][i] != base) {
                    flag = false;
                    break;
                }
            }
            if(!flag)
                break;
            i++;
        }
        return strs[0].substr(0, i);
    }
};
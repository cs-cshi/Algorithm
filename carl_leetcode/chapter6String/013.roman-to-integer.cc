/**
 * 13. 罗马数字转整数
 * https://leetcode.cn/problems/roman-to-integer/
*/
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, int> mmap = {
        {"I", 1},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000}
    };

    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int romanToInt2(string s) {
        int n  = s.size();
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i + 1 < n && s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')){
                ans += mmap[s.substr(i, 2)];
                i++;
            }
            else if(i + 1 < n && s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')){
                ans += mmap[s.substr(i, 2)];
                i++;
            }
            else if (i + 1 < n && s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')){
                ans += mmap[s.substr(i, 2)];
                i++;
            }else
                ans += mmap[string(1,s[i])];
        }
        return ans;
    }

    int romanToInt(string s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int value = symbolValues[s[i]];
            if (i < n - 1 && value < symbolValues[s[i + 1]]) {
                ans -= value;
            } else {
                ans += value;
            }
        }
        return ans;
    }
};
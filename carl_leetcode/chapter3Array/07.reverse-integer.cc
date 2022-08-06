/**
 * 7. 整数反转
 * 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
 * 如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
*/

#include <iostream>

using namespace std;


class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0) {
            if(INT_MAX / 10 < ans || INT_MIN / 10 > ans)
                return 0;
            
            int digit = x % 10;     // 有正负
            // cout << digit << endl;
            x /= 10;
            ans = ans * 10 + digit;
        }
        return ans;
    }
};
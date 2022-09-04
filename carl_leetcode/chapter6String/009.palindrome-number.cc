/**
 * 9. 回文数
 * 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
 * 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * https://leetcode.cn/problems/palindrome-number/
*/


class Solution {
public:
    // 遍历一半就行
    bool isPalindrome(int x) {
        if(x < 0 || ( x % 10 == 0 && x != 0))
            return false;
        int reverseNum = 0;
        while( x > reverseNum) {
            reverseNum = reverseNum * 10 + x %  10;
            x /= 10;
        }
        return x == reverseNum || x == reverseNum / 10;
    }
};
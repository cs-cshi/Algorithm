/**
 * 11. 盛最多水的容器
 * 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 返回容器可以储存的最大水量。
 * 说明：你不能倾斜容器。
 * 链接：https://leetcode.cn/problems/container-with-most-water
*/

#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n == 0 || n == 1)
            return 0;

        int left = 0;
        int right = n - 1;
        int ans = INT_MIN;
        
        while(left < right) {
            ans = max(min(height[left],height[right]) * (right - left), ans);
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return ans == INT_MIN ? 0 : ans;
    }
};
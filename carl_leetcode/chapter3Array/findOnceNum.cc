/**
 * n 个数中，2 个数出现 1 次，其他数出现两次，找出这两个数
 * O(n) 时间复杂度，O(1) 空间复杂度
 */
#include <vector>
#include <iostream>

using namespace std;

void findOnceNum(vector<int> &nums)
{
    int c = 0; // 求出 num1 与 num2 的异或值
    for (int i = 0; i < nums.size(); i++)
        c ^= nums[i];

    // int flag = c & (~(c - 1)) - 1;  // 求出 num1 与 num2 最低位不同的位置

    int flag = 0;
    while(((c >> flag) & 1) == 0)
        flag++;

    cout << flag << endl;

    int num1 = 0;
    int num2 = 0;

    for(int i = 0; i < nums.size(); i++) {
        if((nums[i] >> flag) & 1) {
            num1 ^= nums[i];
        }else
            num2 ^= nums[i];
    }

    cout << num1 <<  "   " << num2 << endl;
}

int main()
{
    vector<int> nums = {4,1,1,2,8,2,8,3,3,5};
    findOnceNum(nums);
    return 0;
}
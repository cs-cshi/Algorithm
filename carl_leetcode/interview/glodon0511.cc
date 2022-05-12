#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void solve(int n, int k, vector<int> nums)
{
    sort(nums.begin(), nums.end());

    // 滑动窗口左右边界初始化
    int left_index = 0;
    int left = nums[left_index];

    int right = left + k;
    int max1 = INT_MIN;
    int max2 = INT_MIN;

    // 记录当前滑动窗口中的元素个数
    int count = 0;

    // 窗口 count 初始化
    int i = 0;
    while (i < nums.size() && nums[i++] <= right)
        count++;
    max1 = count;

    while (i < nums.size())
    {
        // 口往右移一位
        while (left_index < nums.size() - 1 && nums[left_index] == nums[left_index + 1])
        {
            left_index++;
            count--;
        }
    }
}

int solve2(int n, int k, vector<int> &nums)
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> nums;
    int num;
    while(cin >> num)
        nums.push_back(num);

    sort(nums.begin(), nums.end());
    int right_val = 0;
    int right_index = 0;
    // [left, right]
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // 第一口
        int count1 = 0;
        right_index = i;
        right_val = nums[i] + k; //  第一口右界值
        while (right_index < nums.size() && nums[right_index++] <= right_val)
            count1++;

        // 第二口，滑动窗口最值
        if (right_index == nums.size())
            break;
        // 初始化
        int count2 = 0;
        right_val = nums[right_index] + k; // 右界值
        int j = right_index;               // 左界索引
        // 初始化
        while (right_index < nums.size() && nums[right_index++] <= right_val)
            count2++;

        int count2Max = count2;
        while (right_index < nums.size()) // 左界遍历
        {
            // 左移一个数值
            j++;
            count2--;
            while (j < right_index && j < nums.size() && nums[j] == nums[j - 1])
            {
                j++;
                count2--;
            }

            if (j == nums.size())
                break;

            right_val = nums[j] + k;
            while (right_index < nums.size() && nums[right_index++] <= right_val)
                count2++;

            count2Max = max(count2Max, count2);
        }

        ans = max(ans, count1 + count2Max);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 5, 2, 3, 1, 5, 4};
    int res = solve2(7, 1, nums);
    cout << res << endl;
}
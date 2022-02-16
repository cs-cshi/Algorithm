/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
*/
#include <vector>
#include <unordered_set>

using std::unordered_set;
using std::vector;

// 遍历数组，使用集合存储每个元素：若集合中已有当前元素，从集合中删除当前元素，最后剩下的就是只有一次的元素
int singleNumber(vector<int> &nums)
{
    unordered_set<int> nums_set;
    for (const int &num : nums)
    {
        if (nums_set.count(num))
            nums_set.erase(num);
        else
            nums_set.insert(num);
    }
    return *(nums_set.begin());
}

/*
异或
1. 任何数和 0 异或，结果仍然是原来的数
2. 任何数和其自身异或，结果是 0
3. 异或满足交换律和结合律
*/
int singleNumber(vector<int> &nums)
{
    int ret = 0;
    for(const int& num:nums)
        ret ^= num;
    return ret;
}

int main()
{
    vector<int> nums = {4,1,2,1,2};
    int result = singleNumber(nums);
    return 0;
}
// leetcode 数组类题目刷题
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void outputVector(const vector<int> &);

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // 两数之和
    // 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {0, 0};
    }

    vector<int> twoSumHash(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hashtable.end() != hashtable.find(target - nums[i]))
                return {hashtable[target - nums[i]], i};
            hashtable[nums[i]] = i;
        }
        return {};
    }

    // 删除有序数组中的重复项
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        int index = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[index] != nums[i])
            {
                ++index;
                nums[index] = nums[i];
            }
        }
        return index + 1;
    }

    // 移除元素
    int removeElement(vector<int> &nums, int val)
    {
        int first = 0;
        int last = nums.size() - 1;
        int temp = 0;

        while (first <= last)
        {
            if (nums[first] == val)
            {
                nums[first] = nums[first] ^ nums[last];
                nums[last] = nums[first] ^ nums[last];
                nums[first] = nums[first] ^ nums[last];
                last--;
            }
            else
            {
                first++;
            }
        }
        return first;
    }

    // 搜索插入位置
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] >= target)
            {
                right = mid - 1;
            }
        }
        return left;
    }

    // 最大子序和
    int maxSubArray(vector<int> &nums)
    {
        // if (nums.size() == 1)
        //     return nums[0];
        int maxSum = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (currentSum < 0)
                currentSum = nums[i];
            else
                currentSum += nums[i];
            if (currentSum >= maxSum)
                maxSum = currentSum;
        }
        return maxSum;
    }

    // 最大子序和
    int maxSubArray2(vector<int> &nums)
    {
        int maxSum = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            // if(currentSum < 0)
            //     currentSum = nums[i];
            // else
            //     currentSum += nums[i];
            currentSum = max(nums[i], currentSum + nums[i]);
            // if( currentSum > maxSum )
            //     maxSum = currentSum;
            maxSum = max(currentSum, maxSum);
        }
        return maxSum;
    }

    int findMaximumSubarray(vector<int> nums, int low, int high)
    {
        if (high == low)
            return nums[low];

        int mid = (low + high) / 2;
        int leftResult = findMaximumSubarray(nums, low, mid);
        int rightResult = findMaximumSubarray(nums, mid + 1, high);
        int crossingResult = findMaxCrossingSubarray(nums, low, mid, high);

        if (leftResult >= rightResult && leftResult >= crossingResult)
            return leftResult;
        else if (rightResult >= leftResult && rightResult >= crossingResult)
            return rightResult;
        else
            return crossingResult;
    }

    int findMaxCrossingSubarray(vector<int> nums, int low, int mid, int high)
    {
        int leftSum = 0;
        int rightSum = 0;
        int sum = 0;
        int leftBegin = 0;
        int rightBegin = 0;

        for (int i = mid; i >= 0; i--)
        {
            sum += nums[i];
            if (sum > leftSum)
            {
                leftSum = sum;
                leftBegin = i;
            }
        }

        sum = 0;
        for (int i = mid + 1; i <= high; i++)
        {
            sum += nums[i];
            if (sum > rightSum)
            {
                rightSum = sum;
                rightBegin = i;
            }
        }
        return leftSum + rightSum;
    }

    ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2)
    {
        ListNode *l3 = new ListNode(0);
        ListNode *head = l3;
        ListNode *cur;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val > l2->val)
            {
                l3->next = l2;
                l2 = l2->next;
                l3 = l3->next;
            }
            else
            {
                l3->next = l1;
                l1 = l1->next;
                l3 = l3->next;
            }
        }

        if (l1 == nullptr)
            l3->next = l2;
        else
            l3->next = l1;

        return head->next;
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        ListNode *cur = new ListNode(0);
        ListNode *head;

        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        head = l1->val <= l2->val ? l1 : l2;
        while (cur1 != nullptr && cur2 != nullptr)
        {
            if (cur1->val <= cur2->val)
            {
                cur->next = cur1;
                cur = cur->next;
                cur1 = cur1->next;
            }
            else
            {
                cur->next = cur2;
                cur = cur->next;
                cur2 = cur2->next;
            }
        }
        //连接最后一个节点。
        if (cur1 == nullptr)
            cur->next = cur2;
        else
            cur->next = cur1;
        return head;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
    }
};

int main()
{
    /* code */
    Solution solution;
    // 1. 两数和
    // vector<int> nums = {3, 2, 4};
    // vector<int> results;
    // results = solution.twoSumHash(nums, 6);

    // 2. 删除有序数组中的重复项
    // vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    // int results = solution.removeDuplicates(nums);

    // 3. 移除元素
    // vector<int> nums = {3,2,2,3};
    // int val = 2;
    // int results = solution.removeElement(nums, val);

    // 4. 搜索插入位置
    // vector<int> nums = {1,3,5,6};
    // int val = 5;
    // int results = solution.searchInsert(nums, val);

    // 5. 最大子序和
    // vector<int> nums = {-1};
    // int results = solution.findMaximumSubarray(nums, 0, nums.size() - 1);
    // cout << results << endl;
    // outputVector(nums);

    vector<int> arr1 = {1, 2, 4};
    vector<int> arr2 = {1, 3, 4};

    ListNode node1(1);
    ListNode *p1 = &node1;

    ListNode node2(2);
    node1.next = &node2;

    ListNode node3(3);
    node2.next = &node3;

    ListNode node4(4);
    node3.next = &node4;

    ListNode node5(5);
    node4.next = &node5;

    node5.next = nullptr;

    while (p1)
    {
        cout << p1->val << endl;
        p1 = p1->next;
    }

    // ListNode node33(4);
    // node22.next = &node33;

    // node33.next = nullptr;

    // ListNode *result = solution.mergeTwoLists(p1, p2);
    // while (result != nullptr)
    // {
    //     cout << "result " << result->val << endl;
    //     result = result->next;
    // }

    // for (int i = 0; i < arr1.size(); i++)
    // {

    //     ListNode *temp1 = new ListNode(arr1[i]);
    //     ListNode *temp2 = new ListNode(arr2[i]);
    //     l2->next = temp2;
    //     l1->next = temp1;
    //     l1 = l1->next;
    //     l2 = l2->next;
    // }

    // while (p1 != nullptr)
    // {

    //     cout << "p1: " << p1->val << endl;
    //     p1 = p1->next;
    // }
    // // while (head1->next != nullptr)
    // //     cout << "head1: " << head1->val;

    // while (p2 != nullptr)
    // {
    //     cout << "p2 " << p2->val << endl;
    //     p2 = p2->next;
    // }
    // while (head2->next != nullptr)
    //     cout << "head2: " << head2->val;

    return 0;
}

void outputVector(const vector<int> &items)
{
    for (int item : items)
        cout << item << " ";
    cout << endl;
}

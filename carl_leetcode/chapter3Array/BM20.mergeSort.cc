/**
 * BM20 数组中的逆序对
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
 * 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P mod 1000000007
 * 链接：https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj%3Ftab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295
 */

#include <algorithm>
#include <vector>
#include <iostream>

using namespace ::std;

// 归并排序算法
int InversePairs(vector<int> data)
{
    int result = 0;
    int len = data.size();
    vector<int> b(data.size());
    // 划分
    for (int seg = 1; seg < data.size(); seg += seg)
    {
        // 两两 seg 之间归并,[start,mid)[mid,high)
        for (int start = 0; start < len; start += seg + seg)
        {
            int mid = min(start + seg, len);    
            int high = min(start + seg + seg, len);
            int start1 = start, start2 = mid;   //  注意是左闭右开区间
            int k = start;
            while (start1 < mid && start2 < high)
            {
                if (data[start1] > data[start2])
                {
                    b[k++] = data[start2++];
                    // 核心：归并的时候，两两区间都已经有序，如果 pre 区间中某个数值大于 last 区间某个数值，那个 pre 区间中那个数值之后的所有数值均会大于 last 区间的那个数值
                    result += mid - start1;     // 注意是 [mid,start1) 区间，不需要 +1
                    result %= 1000000007;
                }
                else
                    b[k++] = data[start1++];
            }

            while (start1 < mid)
                b[k++] = data[start1++];

            while (start2 < high)
                b[k++] = data[start2++];
        }
        
        // 将完成一层归并的临时数组赋值给原来数组
        for (int i = 0; i < data.size(); i++)
            data[i] = b[i];
    }
    return result;
}

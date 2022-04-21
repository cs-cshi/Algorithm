/**
 * BM21 旋转数组的最小数字
 * 链接：https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj%3Ftab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295
 */

#include <vector>

using namespace ::std;

class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0;
        int right = rotateArray.size() - 1;
        // [left, right) 左闭右开区间
        while (left < right)
        {
            int mid = ((right - left) >> 1) + left;
            if (rotateArray[mid] > rotateArray[right])  //  target 在右区间
                left = mid+1;
            else if(rotateArray[mid] < rotateArray[right])  // target 在左区间
                right = mid;
            else  // 慢缩小
                right--;
        }
        return rotateArray[left];
        // return rotateArray[left] > rotateArray[right] ? rotateArray[right] : rotateArray[left];
    }
};
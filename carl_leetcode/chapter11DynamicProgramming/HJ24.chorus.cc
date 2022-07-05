/**
 * HJ24 合唱队
 * N 位同学站成一排，音乐老师要请最少的同学出列，使得剩下的 K 位同学排成合唱队形。
 * 设 K 位同学从左到右依次编号为 1，2…，K ，他们的身高分别为T1, T2, … ,TK ，若存在 i(1 ≤ i ≤ K) 使得 T1 < T2 <......< Ti−1 < Ti， 且 Ti > Ti+1 >......>TK，则称这KK名同学排成了合唱队形。
 * 通俗来说，能找到一个同学，他的两边的同学身高都依次严格降低的队形就是合唱队形。
 * 链接：https://www.nowcoder.com/practice/6d9d69e3898f45169a441632b325c7b4?tpId=37&tqId=21247&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D100%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
*/

#include <vector>
#include <iostream>


using namespace std;

int takeChorus(vector<int> &nums) {
    // dp1[i],  以 i 结尾的子数组最长递增子序列长度
    vector<int> dp1(nums.size(), 1);
    
    for(int i = 1; i < nums.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j])
                dp1[i] = max(dp1[i], dp1[j] + 1);
        }
    }
    
    // dp2[i]，数组从右往左，以 i 结尾的子数组最长递增子序列长度
    vector<int> dp2(nums.size(), 1);
    for(int i = nums.size() - 2; i >= 0; i--) {
        for(int j = nums.size() - 1; j > i; j--) {
            if(nums[i] > nums[j])
                dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }
    
    int ans = 0;
    for(int i = 0; i < nums.size(); i++) {
        ans = max(ans, dp1[i] + dp2[i]);
    } 
    
    // 最高点重复算了两次，需要 + 1
    return nums.size() - ans + 1;
}


int main() {
    int n;
    int num;
    vector<int> nums;
    while(cin >> n) {
        for(int i = 1; i <= n; i++){
            cin >> num;
            nums.push_back(num);
        }
    }
    cout << takeChorus(nums) << endl;
    return 0;
}
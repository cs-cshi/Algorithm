#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans = 0, status = 0, n = s.length();
        vector<int> pos(1 << 26, -1);
        pos[0] = 0;
        for (int i = 0; i < n; ++i) {
            int num = s[i] - 'a';
            status ^= 1 << num;
            if (~pos[status]) {
                ans = max(ans, i + 1 - pos[status]);
            } else {
                pos[status] = i + 1;
            }
        }
        return ans;
    }
};

int main(){
    string s = "zthtzh";
    Solution solution;
    int ans = solution.findTheLongestSubstring(s);
    cout << ans << endl;
    return 0;
}

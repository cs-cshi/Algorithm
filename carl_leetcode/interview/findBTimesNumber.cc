#include "bits/stdc++.h"

using namespace std;


int main()
{
    vector<int> t{2,7,4,1,8,1};
    int sum = 0;
    for (int i = 0; i < t.size(); i++)
    {
        sum += t[i];
    }

    int target = sum / 2;

    vector<int> dp(target + 1, 0);

    for (int i = 0; i < t.size(); i++)
    {
        for (int j = target; j >= t[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - t[i]] + t[i]);
        }
    }

    cout << max(sum - dp[target], dp[target]) << endl; 
}
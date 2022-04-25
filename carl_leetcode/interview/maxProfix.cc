#include <vector>
#include <algorithm>
#include <iostream>
// #include <numeric>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;

int maxProfix(vector<int> &prices)
{
    int result = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        result = max(result, prices[i] - minPrice);
    }
    return result;
}

int main()
{
    // vector<int> prices = {7, 1, 5, 3, 6, 4};
    vector<int> prices = {7, 6, 4, 3, 1};
    int result = maxProfix(prices);
    cout << result << endl;
    return 0;
}
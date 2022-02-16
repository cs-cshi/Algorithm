#include <vector>
#include <unordered_map>
#include <utility>

using std::pair;
using std::unordered_map;
using std::vector;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end())
                return {i, iter->second};
            map.insert(pair<int, int>(nums[i], i));
        }
        return {}; 
        
    }
};
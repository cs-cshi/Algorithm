/*
给定一个字符串数组，将字母异位词组合在一起。可以按任意顺序返回结果列表。

字母异位词指字母相同，但排列不同的字符串。

示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

#include <vector>
#include <unordered_map>
#include <string>
#include <array>
#include <numeric>
#include <functional>
#include <algorithm>

using std::accumulate;
using std::array;
using std::hash;
using std::sort;
using std::string;
using std::unordered_map;
using std::vector;

// 将 str 排序后作为 map 的 key
vector<vector<string>> groupAnagrams2(vector<string> &strs)
{
    unordered_map<string, vector<string>> map;

    for (string &str : strs)
    {
        string key = str;
        sort(key.begin(), key.end());
        map[key].emplace_back(str);
    }

    vector<vector<string>> answer;

    for (auto it = map.begin(); it != map.end(); it++)
        answer.emplace_back(it->second);

    return answer;
}

/*
array 容器是 C++ 11 标准中新增的序列容器，简单地理解，它就是在 C++ 普通数组的基础上，添加了一些成员函数和全局函数。
*/

/*
lambda 表达式定义了一个匿名函数，并且可以捕获一定范围内的变量。
  - 语法：[ capture ] ( params ) opt -> ret { body; };
  - 其中 capture 是捕获列表，params 是参数表，opt 是函数选项，ret 是返回值类型，body是函数体。
  - 如果希望去修改按值捕获的外部变量，需要显式指明 lambda 表达式为 mutable：
*/
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    // 自定义对 array<int, 26> 类型的哈希函数
    auto arrayHash = [fn = hash<int>{}](const array<int, 26> &arr) -> size_t
    {
        // << 左移一位，乘以2
        // ^ 异或运算符
        return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num)
                          { return (acc << 1) ^ fn(num); });
    };

    // decltype：通过编译来自动确定类型
    unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
    for (string &str : strs)
    {
        array<int, 26> counts{};
        int length = str.length();
        for (int i = 0; i < length; ++i)
        {
            counts[str[i] - 'a']++;
        }
        mp[counts].emplace_back(str);
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        ans.emplace_back(it->second);
    }
    return ans;
}

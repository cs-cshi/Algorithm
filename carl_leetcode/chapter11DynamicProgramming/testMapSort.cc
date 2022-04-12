/**
 * 用来测试 cpp map 根据 value 排序
*/

#include <string>
#include <map>
#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;

class node
{
public:
    int val;
    string str;

public:
    node() : val(0), str("") {}
    node(int val, string str) : val(val), str(str) {}
};

struct Cmp
{
    bool operator()(node const &node1, node const &node2) const
    {
        // return node1.val < node2.val;
        if (node1.val < node2.val)
            return true;
        else if (node1.val > node2.val)
            return false;
        else
            return node1.str < node2.str;
    }
};

int main()
{

    map<node, int, Cmp> map;
    map.insert({node{1, "def"}, 0});
    map.insert({node{1, "abc"}, 0});
    map.insert({node{1, "bcd"}, 0});

    for (auto iter : map)
        cout << iter.first.str << endl;
}

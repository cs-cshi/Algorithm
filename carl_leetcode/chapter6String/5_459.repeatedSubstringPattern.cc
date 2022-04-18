#include <string>
#include <iostream>

using std::cout;
using std::string;

class Solution
{
public:
    void getNext(int *next, const string &s)
    {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++)
        {
            while (j >= 0 && s[i] != s[j + 1])
                j = next[j];

            if (s[i] == s[j + 1])
                j++;

            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s)
    {
        if (s.size() == 0)
            return false;

        int len = s.size();
        int next[len];
        getNext(next, s);
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0)
            return true;
        return false;
    }

    void getNext2(int *next, const string &s)
    {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[i] != s[j])
                j = next[j - 1];

            if (s[i] == s[j])
                j++;

            next[i] = j;
        }
    }

    bool repeatedSubstringPattern2(string s)
    {
        if (s.size() == 0)
            return false;

        int len = s.size();
        int next[len];
        getNext2(next, s);
        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0)
            return true;
        return false;
    }
};

int main()
{
    Solution solution;
    string s = "asdfasdfasdf";
    int next[s.size()];
    solution.getNext2(next, s);
    for (int i = 0; i < s.size(); i++)
        cout << next[i] << " ";
}
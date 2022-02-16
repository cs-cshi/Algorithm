#include <iostream>
#include <string>

using std::string;

string replaceSpace2(string s)
{
    int count = 0, len = s.size();

    for (char c : s)
    {
        if (c == ' ')
            count++;
    }

    s.resize(len + 2 * count);

    for (int i = len - 1, j = s.size() - 1; i < j; i--, j--)
    {
        if (s[i] != ' ')
            s[j] = s[i];
        else
        {
            s[j] = '0';
            s[j - 1] = '2';
            s[j - 2] = '%';
            j -= 2;
        }
    }
    return s;
}

string replaceSpace(string s)
{
    string res;
    
    for(auto c : s)
    {
        if(c == ' ')
        {
            res.push_back('%');
            res.push_back('2');
            res.push_back('0');
        }else
            res.push_back(c);
    }
    return res;
}

int main()
{
    return 0;
}
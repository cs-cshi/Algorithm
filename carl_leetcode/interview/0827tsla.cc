#include <string>
#include <iostream>

using namespace std;

string solve(string s)
{
    int n = s.size();
    bool odd = n % 2;
    for (int i = 0; i < s.size() / 2 + 1; i++)
    {
        if (s[i] != 'a')
        {
            if (odd && i == (n / 2 - 1))
                continue;
            s[i] = 'a';
            return s;
        }
    }
    s[s.size() - 1] = 'b';
    return s;
}

class A
{
public:
    virtual void say()
    {
        cout << "AAA" << endl;
    }
};

class B : public A
{
public:
    virtual void say()
    {
        cout << "BBB" << endl;
    }
};

class C : public B
{
public:
    virtual void say()
    {
        cout << "CCC" << endl;
    }
};

int main()
{
    C c;
    ((B*)(&c))->say();
    ((B)c).say();

    return 0;
}
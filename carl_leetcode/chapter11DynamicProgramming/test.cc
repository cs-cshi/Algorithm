#include <iostream>

using namespace ::std;

class Obj
{
public:
    Obj() { puts("Obj()"); }
    Obj(int m) : m(m) { cout << "Obj()"
                             << " " << m << endl; }
    ~Obj() { cout << "~Obj()" << m << endl; }

private:
    int m;
};

void foo(int n)
{
    Obj obj(n);
    if (n == 42)
        throw "life, the universe and everything";
}

int main()
{
    try
    {
        foo(41);
        foo(42);
    }
    catch (const char *s)
    {
        puts(s);
    }
}
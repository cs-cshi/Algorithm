#include <iostream>

using namespace std;

class Test
{
public:
    Test(int i)
    {
        this->i = i;
        cout << "constructor~" << i << endl;
    }

    ~Test()
    {
        cout << "deconstructor~" << i << endl;
    }

private:
    int i;
};

class wrap
{
public:
    wrap(Test *test) : test(test) {}
    ~wrap()
    {
        delete test;
    }

private:
    Test *test;
};

int main()
{
    Test *test = new Test(1);
    Test test2(2);
    // wrap test3(test);
    cout << "test begin ... " << endl;
}
#include "bits/stdc++.h"

using namespace std;

class Demo
{
public:
    Demo(string s);
    ~Demo();

private:
    string m_s;
};

Demo::Demo(string s) : m_s(s) { cout << "constructor " << m_s << endl; }

Demo::~Demo() { cout << m_s << endl; }

void func()
{
    //局部对象
    Demo obj1("1");
}

//全局对象
Demo obj2("2");

int main()
{
    //局部对象
    Demo obj3("3");

    // new 创建的对象
    Demo *pobj4 = new Demo("4");
    func();
    cout << "main" << endl;

    string s1 = "first second second third";
    string s2 = "asecond";

    int index = s1.find_first_of(s2);

    if (index < s1.length())
        cout << "Found at index : " << index << endl; // 3
    else
        cout << "Not found" << endl;
    return 0;
}

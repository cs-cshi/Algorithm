// #include <iostream>
#include "bits/stdc++.h"

using namespace std;

int fun(int x) {
    int count = 0;
    while(x)
    {
        count++;
        x = x&(x-1);
    }
    cout << count << endl;
    return 0;
}

int fun2(int m){
    static int n = 0;
    m /= 2;
    m = m*2;
    if(m){
        n = n * m;
        return (fun2(m-2));
    }else
        return(n++);
}

void swap1(int x, int y){
    int t;
    t = x;
    x = y;
    y = t;
}

void swap2(int* x, int* y){
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

void f(char *x){
    x++;
    *x = 'a';
}

int main() {
 /*   int i,r;
    for(int i = 0; i < 2; i++)
    {
        r = fun2(4+i);
        printf("%d\n", r);
    }*/
    // int x,y;
    // x = 1;
    // y = 3;
    // swap1(x,y);
    // cout <<x << "  " << y << endl;
    // x = 1;
    // y = 3;
    // swap2(&x,&y);
    // cout << x <<  "  " << y << endl;
    // int x = 2;
    // int y = 2;
    // int t = x++ || ++y;
    // cout << x << y << t << endl;
    char str [sizeof("wondershare")];
    strcpy(str,"wondershare");
    f(str);
    cout <<str;
    return 0;
}
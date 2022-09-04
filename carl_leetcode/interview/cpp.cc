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
    // char str [sizeof("wondershare")];
    // strcpy(str,"wondershare");
    // f(str);
    // cout <<str;
    // long a[] = {1,2,1.0};
    // char b[] = {'a','b',1234};
    // char c[] = {'e',123,'t'};
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> cost;
    int temp = n;
    while(temp--){
        int num;
        cin >> num;
        cost.push_back(num);
    }
    vector<int> times;
    vector<int> timesCopy(m ,3);
    int temp2 = m;
    while(temp2--){
        int num;
        cin >> num;
        times.push_back(num);
    }
    // int n = 5;
    // int m = 1;
    // vector<int> cost = {1,1,1,1,1};
    // vector<int> times = {3};
    // vector<int> timesCopy(m ,3);


    int success = 0;
    for(int i = 0; i < n; i++) {
        if(cost[i] > m)
            break;

        if(times[cost[i] - 1] <= 0 || timesCopy[cost[i] - 1] <= 0)
            break;
        
        times[cost[i] - 1]--;
        timesCopy[cost[i] - 1]--;
        success++;
    }

    cout << success * 30 << endl;

    return 0;
}
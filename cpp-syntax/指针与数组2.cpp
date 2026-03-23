#include <bits/stdc++.h>
using namespace std;

int *arrf()
{
    static int arr[3] = {1, 2, 3};
    return arr;
}
int main()
{
    for (int i = 0; i < 3; i++)
    {
        cout << arrf()[i] << endl;
    }
    int i = 1;
    int *p = &i;
    cout << (p[1]==*(p+1)) << endl; // 任何指针都有p[n]语法糖 
}
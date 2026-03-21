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
}
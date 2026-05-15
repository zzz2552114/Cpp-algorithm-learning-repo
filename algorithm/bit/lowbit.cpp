#include<bits/stdc++.h>
using namespace std;
int lowbit(int m)
{
    int cnt = 0;
    while (m)
    {
        m -= (m & -m);
        cnt++;
    }
    return cnt;
}
int main(){
    for (int i = 0; i <= 10;i++){
        cout << lowbit(i) << ' ';
    }
}
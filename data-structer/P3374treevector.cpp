#include<bits/stdc++.h>
using namespace std;
vector<int> arr, tr;
int n, m;
int lowbit(int x){
    return x & -x;
}
void add(int i,long long x){
    while(i<=n){
        tr[i] += x;
        i += lowbit(i);
        cout << i << ' ' << lowbit(i) <<'\n';
    }
}
long long query(int i){
    long long res = 0;
    while(i>0){
        res += tr[i];
        i -= lowbit(i);
    }
    return res;
}
int main(){
    cin >> n >> m;
    arr.resize(n + 1);
    tr.resize(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
        add(i, arr[i]);
    }
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            add(b, c);
        else if (a == 2)
            cout << query(c) - query(b - 1) << '\n';
    }
}

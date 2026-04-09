#include<bits/stdc++.h>
using namespace std;
int n, m;
const int maxN = 1e5 + 10;
int arr[maxN];
bool check(int mid){
    int cnt = 1,pos = 0;
    for (int i = 1; i <= n-1;i++){
        if(arr[i]-arr[pos] >= mid) {
            cnt++;
            pos = i;
        }
    }
    return cnt >= m;// 这里表示，在mid最小距离要求下，可以实现放m牛，所以mid可以大一点
}
int main(){
    cin >> n >> m;
    for (int i = 0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, &arr[n]);
    int l = 0, r = 1e9;
    while(l<r){
        int mid = (l + r + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout << l << endl;
}
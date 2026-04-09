#include<bits/stdc++.h>
using namespace std;
int n, k;
const int maxN = 1e5;
int arr[maxN];
bool check(int mid){
    int cnt = 0;
    for (int i = 0; i < n;i++){
        cnt += arr[i] / mid;
    }
    return cnt >= k; // 如果可以，cnt>=k，返回1，说明mid可能可以再扩大
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int l = 0,r = 1e8;
    while(l<r){
        int mid = (l + r+1) / 2;
        if(check(mid))
            l = mid;
        else
            r = mid-1;
    }
    cout << l << endl;
}
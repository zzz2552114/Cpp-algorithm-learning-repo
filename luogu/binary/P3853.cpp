#include<bits/stdc++.h>
using namespace std;
int l, n, k;
const int maxN = 1e6 + 10;
int arr[maxN];
bool check(int mid){
    int cnt = 0;
    for (int i = 1; i < n;i++){
        cnt += (arr[i] - arr[i - 1] - 1) / mid;
    }
    return cnt <= k;
}
int main(){
    cin >> l >> n >> k;
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int left = 1,r = 1e8;
    while(left<r){
        int mid = (left + r) / 2;
        if(check(mid)) r = mid;
        else left = mid+1;
    }
    cout<< left << endl;
}
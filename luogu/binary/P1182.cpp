#include<bits/stdc++.h>
using namespace std;
int n, m;
const int maxN = 1e5 + 10;
int arr[maxN];
bool check(long long mid){
    int cnt = 1,sum = 0;
    for (int i = 0; i < n;i++){
        if(sum+arr[i]>mid){
            sum = arr[i];
            cnt++;
        }
        else
            sum += arr[i];
    }
    return cnt <= m;
}
int main(){
    cin >> n >> m;
    long long l = 1, r = 1e9;
    for (int i = 0;i<n;i++){
        cin >> arr[i];
        l = max(l,(long long)arr[i]);
    }

    while(l<r){
        long long mid = (l + r) / 2;
        if(check(mid))
            r = mid;
        else
            l = mid+1;
    }
    cout << l << endl;
}
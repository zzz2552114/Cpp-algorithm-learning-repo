#include<bits/stdc++.h>
using namespace std;
int arr[200010],dp[200010][2],prefix[200010];
const int mod = 998244353;
int main(){
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++) cin >> arr[i];
    for(int i = 1;i<=n;i++){
        int t = 0;
        if(arr[i]%2) t = 1;
        prefix[i] = prefix[i-1] + t;
    }
    int ans = 0;
    int cnt0 = 0,cnt1 = 0;
    if((arr[1]+arr[2])%2) cnt1 = 1;
    else cnt0 = 1;
    for(int i = 3;i<=n;i++){
        if(arr[i]%2 == 1){
            ans = (ans + cnt1) % mod;
            
    }
}

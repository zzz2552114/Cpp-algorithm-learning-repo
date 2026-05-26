#include<bits/stdc++.h>
using namespace std;
int arr[200010];
int dp[200010];
int main(){
    int n, l, r;
    cin >> n >> l >> r;
    memset(dp, 0xc0, sizeof(dp));
    for (int i = 0; i <= n;i++) cin >> arr[i];
    dp[0] = 0;
    for (int i = l;i<=n;i++){
        for (int j = max(0, i - r); j <= i - l;j++){
            dp[i] = max(dp[i], dp[j] + arr[i]);
        }
    }
    int res = -1e9;
    for (int i = max(0, n - r + 1);i<=n;i++)
        res = max(res, dp[i]);
    cout << res;
}
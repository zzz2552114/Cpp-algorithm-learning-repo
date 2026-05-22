#include<bits/stdc++.h>
using namespace std;
int arr[2010];
long long dp[2010][2010];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++) cin >> arr[i];
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= i;j++){
            if(j==0) dp[i][0] = dp[i-1][0] + i*arr[n-i+1];
            else if(j==i)
                dp[i][i] = dp[i - 1][i - 1] + i * arr[i];
            else{
                dp[i][j] = max(dp[i - 1][j - 1] + i * arr[j], dp[i - 1][j] + i * arr[n - (i - j)+1]);
            }
        }
    }
    long long res = 0;
    for (int i = 0; i <= n;i++){
        res = max(res, dp[n][i]);
    }
    cout << res;
}
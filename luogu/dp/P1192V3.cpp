#include<bits/stdc++.h>
using namespace std;
int n, k;
long long dp[100005];
int main(){
    cin >> n >> k;
    dp[0] = 1;
    dp[1] = 1;
    int j = 2;
    while(j<=n){
        if(j>k){
            for (int t = j - 1; t >= j - k;t--) dp[j] = (dp[j]+dp[t])%100003;
        }
        else if(j<=k){
            for (int t = 0; t < j;t++) dp[j] = (dp[j]+dp[t])%100003;
        }
        j++;
    }
    cout << dp[n] << endl;
}
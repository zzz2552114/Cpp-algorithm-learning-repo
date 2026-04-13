#include<bits/stdc++.h>
using namespace std;

int n,k,dp[100005];
int dfs(int n){
    if(n<=0) return 0;
    if(dp[n]) return dp[n];
    int ans = 0;
    if(n<=k) ans++;
    for (int i = 1;i<=k;i++){
        ans = (ans+dfs(n - i))%100003;
    }
    dp[n] = ans;
    return ans;
}
int main(){
    cin >> n >> k;
    cout << dfs(n) << '\n';
}
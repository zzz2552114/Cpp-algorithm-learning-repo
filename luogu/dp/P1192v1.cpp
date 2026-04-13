#include<bits/stdc++.h>
using namespace std;
// 先写最基础款的暴力搜索
int n, k;
int dfs(int n){
    if(n<=0) return 0;
    if(n==1) return 1;
    int ans = 0;
    if(n<=k) ans++;
    for (int i = 1; i <= k;i++){
        ans += dfs(n-i);
    }
    return ans;
}
int main(){
    cin >> n >> k;
    cout << dfs(n) << '\n';
}
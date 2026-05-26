#include<bits/stdc++.h>
using namespace std;
int arr[25],dp[25][20];
int n, m;
vector<int> valid;
int ans = 0;
void dodp(vector<int>& vec){
    int dp[2005];
    int cnt = 0;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n - m;i++){
        for (int j = 2001; j >= vec[i];j--){
            dp[j] |= dp[j - vec[i]];
        }
    }
    for (int j = 1; j <= 2001;j++)
        if(dp[j]) cnt++;
    ans = max(ans, cnt);
}
void dfs(int i,int c){ 
    // i表示处理到第i个元素了，c表示选择了c个
    if(c>n-m)
        return;
    if(i>n){
        if(c == n-m) dodp(valid);
        return;
    }
    valid.push_back(arr[i]);
    dfs(i + 1, c + 1);
    valid.pop_back();
    dfs(i + 1, c);
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
    }
    valid.push_back(0);
    dfs(1, 0);
    cout << ans;
}
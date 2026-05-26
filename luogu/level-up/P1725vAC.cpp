#include<bits/stdc++.h>
using namespace std;
int arr[200010],dp[200010];
int main(){
    int n, l, r;
    cin >> n >> l >> r;
    memset(dp, 0xc0, sizeof(dp));
    for (int i = 0; i <= n; i++)
        cin >> arr[i];
    dp[0] = 0;
    deque<int> q;
    for (int i = l; i <= n;i++){
        int p = i - l;
        while(!q.empty() && dp[q.back()] <= dp[p])
            q.pop_back();
        q.push_back(p);
        while(!q.empty() && i - q.front() > r)
            q.pop_front();
        dp[i] = dp[q.front()] + arr[i];
    }
    int res = -1e9;
    for (int i = max(0, n - r + 1); i <= n; i++)
        res = max(res, dp[i]);
    cout << res;
}
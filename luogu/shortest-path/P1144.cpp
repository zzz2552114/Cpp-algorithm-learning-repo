#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int mod = 100003;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n + 1);
    for (int i = 1; i <= m;i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    // 宽搜，最短路的话只需要计算长度即可
    vector<int> dis(n + 1, inf);
    vector<int> vis(n + 1, 0);
    vector<int> dp(n + 1, 0);
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    dp[1] = 1;
    vis[1] = 1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for (int i = 0; i < (int)vec[curr].size();i++){
            int node = vec[curr][i];
            if(!vis[node]){
                dis[node] = dis[curr] + 1;
                vis[node] = 1;
                dp[node] = dp[curr] % mod;
                q.push(vec[curr][i]);
            }
            else{
                if(dis[node]==dis[curr]+1){
                    dp[node] = (dp[node] + dp[curr]) % mod;
                }
            }
        }
    }
    for (int i = 1; i <= n;i++)
        cout << dp[i] << '\n';
}
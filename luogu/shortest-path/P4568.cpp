#include<bits/stdc++.h>
using namespace std;
struct datas{
    int node, w;
};
bool cmp(const datas& a,const datas& b){
    return a.w > b.w;
}
int main(){
    int n, m, k,s,t;
    cin >> n >> m >> k >> s >> t;
    vector<vector<datas>> vec(n);
    for (int i = 1; i <= m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
        vec[b].push_back({a, c});
    }
    int dp[10010][15];
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i <= k;i++)
        dp[s][i] = 0;
    // 状态设计: dp[i][used]，以s为起点，i为终点，用了used张免费票的情况
    // 对每个used进行一次dijkstra
    // 要想一想循环的顺序

    for (int u = 0; u <= k;u++){
        priority_queue<datas,vector<datas>,decltype(&cmp)> prq(cmp);
        vector<int> vis(n,0);
        prq.push({s,0});
        while(!prq.empty()){
            datas curr = prq.top();
            prq.pop();
            int cn = curr.node, cw = curr.w;
            if(vis[cn])
                continue;
            vis[cn] = 1;
            for (int i = 0; i < vec[cn].size();i++){
                int nx = vec[cn][i].node;
                if(vis[nx]) continue;
                dp[nx][u] = min(dp[nx][u],dp[cn][u]+vec[cn][i].w);
                if(u>0)
                    dp[nx][u] = min(dp[nx][u], dp[cn][u - 1]);
                prq.push({nx, dp[nx][u]});
            }
        }
    }
    cout << dp[t][k];
}
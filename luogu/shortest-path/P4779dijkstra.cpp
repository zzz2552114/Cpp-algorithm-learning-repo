#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9*2;
struct datas{
    int node, w;
};
bool cmp(const datas& a,const datas& b){
    return a.w > b.w;
}
int main(){
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<datas>> mp(n+1);
    for (int i = 1; i <= m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        mp[u].push_back({v, w});
    }
    priority_queue<datas, vector<datas>, decltype(&cmp)> prq(cmp);
    vector<bool> vis(n + 1,0);
    vector<int> dis(n + 1,inf);
    dis[1] = 0;
    prq.push({1,0});
    while(!prq.empty()){
        datas curr = prq.top();
        prq.pop();
        int cn = curr.node;
        if(vis[cn]) continue;
        dis[cn] = curr.w;
        vis[cn] = 1;
        for (int i = 0; i < (int)mp[cn].size();i++){
            prq.push({mp[cn][i].node, mp[cn][i].w+dis[cn]});
        }
    }
    for (int i = 1; i <= n;i++)
        cout << dis[i] << ' ';
}
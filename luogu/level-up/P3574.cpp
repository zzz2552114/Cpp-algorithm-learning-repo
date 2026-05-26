#include<bits/stdc++.h>
using namespace std;
int times[500010];
int n;
vector<vector<int>> children;
vector<int> dp;
vector<int> g;
vector<int> vis;
int gfs(int u){
    // 这里是处理路程时间
    vis[u] = 1;
    for(auto v:children[u]){
        if(vis[v]) continue;
        g[u] += gfs(v)+2;
    }
    return g[u];
}
void dfs(int u)
{   // u表示处理到第u个了
    // 状态转移，t是子节点的所有t的和+子节点个数*2，安装时间怎么转移？
    return;
}
int main(){
    cin >> n;
    for (int i = 1; i <= n;i++) cin >> times[i];
    children.resize(n + 1);
    for (int i = 1; i < n;i++){
        int a, b;
        cin >> a >> b;
        children[a].push_back(b);
        children[b].push_back(a);
    }

    // 需要先预处理路程时间
    dp.resize(n + 1);
    g.resize(n + 1);
    vis.resize(n + 1);
    gfs(1);
    for (int i = 1; i <= n;i++) cout << g[i] << ' ';
}
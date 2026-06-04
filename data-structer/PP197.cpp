#include<bits/stdc++.h>
using namespace std;

int cnt;

vector<int> fa, rk;
int finds(int x){
    if(fa[x] == x) return x;
    return fa[x] = finds(fa[x]);
}
void unions(int x,int y){
    int fx = finds(x);
    int fy = finds(y);
    if(fx == fy) return;
    if(rk[fx]>rk[fy]) fa[fy] = fx;
    else if(rk[fy]>rk[fx]) fa[fx] = fy;
    else {
        fa[fy] = fx;
        rk[fx]++;
    }
    cnt--;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> neib(n);
    for (int i = 1; i <= m;i++){
        int x, y;
        cin >> x >> y;
        neib[x].push_back(y);
        neib[y].push_back(x);
    }
    int k;
    cin >> k;
    vector<int> conq;
    vector<int> vis(n);
    for (int i = 1; i <= k;i++){
        int t;
        cin >> t;
        conq.push_back(t);
        vis[t] = 1;
    }
    cnt = n - k;
    // 下面开始并查集
    fa.resize(n);
    for (int i = 0; i < n;i++) fa[i] = i;
    rk.assign(n, 0);

    vector<int> ans;
    // 思路：反着来，最开始已经被攻占了k天，然后并查集，然后慢慢增加一个星球。
    for (int i = 0; i < n;i++){
        if(vis[i]) continue;
        for(int x:neib[i]){
            if(vis[x]) continue;
            unions(i, x);
        }
    }
    ans.push_back(cnt);
    while(!conq.empty()){
        cnt++;
        int c = conq.back();
        conq.pop_back();
        vis[c] = 0;
        for(int x:neib[c]){
            if(vis[x]) continue;
            unions(c, x);
        }
        ans.push_back(cnt);
    }
    for (auto it = ans.rbegin();it!=ans.rend();it++)
        cout << *it << '\n';
}
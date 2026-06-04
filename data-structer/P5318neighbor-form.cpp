#include<bits/stdc++.h>
using namespace std;
vector<int> vis;
vector<vector<int>> vec;
void dfs(int i)
{
    if(vis[i]) return;
    cout << i <<' ';
    vis[i] = 1;
    for(int x:vec[i]){
        if(vis[x]) continue;
        dfs(x);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vec.resize(n + 1);
    for (int i = 1; i <= m;i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
    }
    for(auto row:vec)
        sort(row.begin(), row.end());
    vis.resize(n + 1);

    dfs(1);
    cout << '\n';
    queue<int> q;
    vector<int> bv(n + 1, 0);
    q.push(1);
    bv[1] = 1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << curr << ' ';
        for(int x:vec[curr]){
            if(bv[x]) continue;
            q.push(x);
            bv[x] = 1;
        }
    }
}
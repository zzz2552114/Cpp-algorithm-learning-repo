#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int mp[105][105],floyd[105][105];
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0;i<105;i++)
        for (int j = 0; j < 105;j++)
            if(j!=i) mp[i][j] = inf;
    for (int i = 1; i <= m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        mp[u][v] = min(mp[u][v], w);
        mp[v][u] = min(mp[v][u], w);
    }
    memcpy(floyd, mp, sizeof(mp));
    for (int k = 1; k <= n;k++){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cout << floyd[i][j] << ' ';
        }
        cout << '\n';
    }
}
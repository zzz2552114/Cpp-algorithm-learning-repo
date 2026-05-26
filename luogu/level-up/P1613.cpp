#include<bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
bool dp[55][55][35];
long long graph[55][55];
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 55;i++)
        for (int j = 0; j < 55;j++)
            graph[i][j] = inf;
    for (int i = 1; i <= m;i++){
        int u, v;
        cin >> u >> v;
        dp[u][v][0] = 1;
        graph[u][v] = 1;
    }
    for (int t = 1; t < 32; t++)
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if(dp[i][k][t - 1] && dp[k][j][t - 1])
                        dp[i][j][t] = 1,graph[i][j] = 1;
            
    for (int k = 1; k <= n;k++)
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= n;j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    cout << graph[1][n];
}
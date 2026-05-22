#include<bits/stdc++.h>
using namespace std;
struct datas{
    int node, w;
};
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<datas>> vec(n + 2);
    for (int i = 1; i <= m;i++){
        int c1, c2, y;
        cin >> c1 >> c2 >> y;
        vec[c2].push_back({c1, y});
    }
    for (int i = 1; i <= n;i++)
        vec[0].push_back({i, 0});
    vector<int> vis(n + 1, 0);
    vector<int> dis(n + 1, 1);
    vector<int> check(n + 1, 1);
    queue<int> q;
    q.push(0);
    dis[0] = 0;
    vis[0] = 1;
    while (!q.empty())
    {
        int cnode = q.front();
        q.pop();
        vis[cnode] = 0;
        for (int j = 0; j < (int)vec[cnode].size(); j++)
        {
            datas curr = vec[cnode][j];
            int nnode = curr.node, nw = curr.w;
            if (dis[nnode] > dis[cnode] + nw)
            {   
                dis[nnode] = dis[cnode] + nw;
                check[nnode] = check[cnode] + 1;
                if(check[nnode]==n+2){
                    cout << "NO";
                    return 0;
                } 
                if (!vis[nnode])
                    q.push(nnode);
            }
        }
    }
    for (int i = 1; i <= n;i++)
        cout << dis[i] << ' ';
}
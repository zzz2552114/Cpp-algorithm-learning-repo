#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct node{
    int x, y;
};
int main(){
    vector<int> xdir{0, 0, 1, -1};
    vector<int> ydir{1, -1, 0, 0};
    int n, m;
    while(cin >> n >> m,n || m){
        vector<vector<char>> mp(n, vector<char>(m));
        vector<vector<int>> dis(n, vector<int>(m,inf));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n;i++)
            for (int j = 0; j < m;j++)
                cin >> mp[i][j];

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        deque<node> q;
        q.push_back({x1, y1});
        dis[x1][y1] = 0;

        while(!q.empty()){
            node curr = q.front();
            q.pop_front();
            int cx = curr.x, cy = curr.y;
            vis[cx][cy] = 1;
            if(cx == x2 && cy == y2){
                cout << dis[x2][y2] << '\n';
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = cx + xdir[i];
                int ny = cy + ydir[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                {
                    if(vis[nx][ny])
                        continue;
                    if (mp[nx][ny] == mp[cx][cy])
                    {
                        if (dis[nx][ny] > dis[cx][cy])
                        {
                            dis[nx][ny] = dis[cx][cy];
                            q.push_front({nx, ny});
                        }
                    }
                    else
                    {
                        if(dis[nx][ny]>dis[cx][cy]+1){
                            dis[nx][ny] = dis[cx][cy] + 1;
                            q.push_back({nx, ny});
                        }
                    }
                }
            }
        }
    }
}
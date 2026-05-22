#include<bits/stdc++.h>
using namespace std;
struct datas{
    int node, w;
};
int n, p, k;
const int inf = 1e9;
bool check(int mid, vector<vector<datas>>& vec)
{
    vector<int> dis(n + 1, inf);
    vector<int> vis(n + 1, 0);
    // 下面用双端队列做0-1bfs
    deque<datas> q;
    q.push_front({1,0});
    dis[1] = 0;
    while(!q.empty()){
        datas c = q.front();
        q.pop_front();
        int cn = c.node, cw = c.w;
        if(vis[cn]) continue;
        vis[cn] = 1;
        for(auto e:vec[cn]){
            int nx = e.node,nw = e.w;
            if(nw>mid) nw = 1;
            else nw = 0;
            if(dis[nx]>dis[cn] + nw){
                dis[nx] = dis[cn] + nw;
                if(nw) q.push_back({nx, nw});
                else
                    q.push_front({nx, nw});
            }
            cout << cn << ' ' << nx << ' ' << nw << ' ' << dis[nx] << '\n';
        }
    }
    cout << dis[n] << '\n';
    if (dis[n] > k)
        return 0;
    return 1;
}
int main(){
    cin >> n >> p >> k;
    vector<vector<datas>> vec(n + 1);
    for (int i = 1; i <= p;i++){
        int a, b, l;
        cin >> a >> b >> l;
        vec[a].push_back({b, l});
        vec[b].push_back({a, l});
    }
    // 要让某条边的最大值最小，二分答案
    int l = 0, r = 1e6 + 10;
    while (l<r){
        int mid = (l + r) / 2;
        cout << l << ' ' << r << ' ' << mid << '\n';
        if(check(mid,vec))
            r = mid;
        else
            l = mid + 1;
    }
    if(l>1e6)
        cout << -1;
    else cout << l;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 4e18;
struct Edge {
    int to;
    ll w;
};
struct State {
    ll dist;   // 当前花费
    int u;     // 当前城市
    int used;  // 已经用了几次免费机会
    bool operator>(const State& other) const {
        return dist > other.dist;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    int s, t;
    cin >> s >> t;
    vector<vector<Edge>> g(n);
    for (int i = 1; i <= m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        // 题目城市编号是 0 到 n-1
        // 无向边，所以两边都加
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    // dis[u][used]：到 u，已经用了 used 次免费机会的最小花费
    vector<vector<ll>> dis(n, vector<ll>(k + 1, INF));
    priority_queue<State, vector<State>, greater<State>> pq;
    dis[s][0] = 0;
    pq.push({0, s, 0});

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        ll d = cur.dist;
        int u = cur.u;
        int used = cur.used;

        // 如果这个状态已经不是最新答案，跳过
        if (d != dis[u][used]) continue;

        for (auto e : g[u]) {
            int v = e.to;
            ll w = e.w;

            // 选择 1：不使用免费机会，正常付钱
            if (dis[v][used] > dis[u][used] + w) {
                dis[v][used] = dis[u][used] + w;
                pq.push({dis[v][used], v, used});
            }

            // 选择 2：使用一次免费机会
            if (used < k && dis[v][used + 1] > dis[u][used]) {
                dis[v][used + 1] = dis[u][used];
                pq.push({dis[v][used + 1], v, used + 1});
            }
        }
    }

    ll ans = INF;

    // 最后可以用了 0 次、1 次、……、k 次免费机会
    for (int used = 0; used <= k; used++) {
        ans = min(ans, dis[t][used]);
    }
    cout << ans << '\n';

    return 0;
}

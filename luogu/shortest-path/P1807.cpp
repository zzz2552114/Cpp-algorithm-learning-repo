#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long inf = 1e15;
struct datas
{
    int node;
    long long w;
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<datas>> vec(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        vec[u].push_back({v,w});
    }
    vector<long long> dis(n + 1, -inf);
    dis[1] = 0;
    for (int i = 1; i < n; i++)
    {
        bool flag = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < (int)vec[i].size(); j++)
            {
                datas curr = vec[i][j];
                int cn = curr.node;
                long long cw = curr.w;
                if (dis[cn] < dis[i] + cw)
                {
                    flag = 0;
                    dis[cn] = dis[i] + cw;
                }
            }
        }
        if (flag)
            break;
    }
    if(dis[n]==-inf)
        cout << -1;
    else
        cout << dis[n];
}
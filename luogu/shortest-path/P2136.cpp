#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct datas{
    int node, w;
};
const string luv = "Forever love";
const int inf = 1e9;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<datas>> vec(n + 1);
    for (int i = 1; i <= m;i++){
        int s, t, w;
        cin >> s >> t >> w;
        vec[s].push_back({t, -w});
    }
    vector<int> dis(n + 1, inf);
    dis[1] = 0;
    // 两遍bellman-ford
    for (int c = 1; c <= n;c++){
        bool flag = 1;
        for (int i = 1; i <= n;i++){
            for (int j = 0; j < (int)vec[i].size();j++){
                datas curr = vec[i][j];
                if(dis[curr.node]>dis[i]+curr.w){
                    dis[curr.node] = dis[i] + curr.w;
                    flag = 0;
                }
            }
        }
        if(c==n && flag == 0){
            cout << luv;
            return 0;
        }
        if(flag)
            break;
    }
    vector<int> dis1(n + 1, inf);
    dis1[n] = 0;
    // 两遍bellman-ford
    for (int c = 1; c <= n; c++)
    {
        bool flag1 = 1;
        for (int i = n; i > 0; i--)
        {
            for (int j = 0; j < (int)vec[i].size(); j++)
            {
                datas curr = vec[i][j];
                if (dis1[curr.node] > dis1[i] + curr.w)
                {
                    dis1[curr.node] = dis1[i] + curr.w;
                    flag1 = 0;
                }
            }
        }
        if (c == n && flag1 == 0)
        {
            cout << luv;
            return 0;
        }
        if (flag1)
            break;
    }
    int ans = min(dis1[1],dis[n]);
    cout << ans;
}
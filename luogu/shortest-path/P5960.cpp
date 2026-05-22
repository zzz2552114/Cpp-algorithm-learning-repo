#include<bits/stdc++.h>
using namespace std;
// 这是一道好题啊，考的是把差分不等式组转化成最短路问题
/*
为什么可以转化呢？我们想，假如一个连通的最短路图，1是起点
那么1到任意由一个边相连的两个点u,v的距离总有这样的关系：
dis[1->u] <= dis[1->v] + w[v->u]; 假设有向边是v->u
这个性质说实话之前没太发现，这可以说是最短路里最好的性质了
根据这个性质，我们构建一个连通图，那么怎么构建连通图呢？仅靠输入数据不保证图是连通的。
我们构建一个超级源点u使得它到每个点的距离是一个常数即可，这个常数就是每个未知数的初始值，会在最短路的过程中不断被约束更改
什么情况下无解呢？有负环则无解，例如a-b<=1 && b-a<=-2
上下相加 0<=-1显然不可能
*/
struct datas{
    int node, w;
};
const int inf = 1e9;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<datas>> vec(n + 1);
    for (int i = 1; i <= m;i++){
        int z, o, w;
        cin >> z >> o >> w;
        vec[o].push_back({z, w});
    }
    vector<int> dis(n + 1,0);
    // for (int i = 1; i <= n;i++) dis[i] = i;
    // 这里是一个小tricky，验证dis数组的初值与答案无关
    for (int c = 1; c <= n + 1; c++)
    {
        bool change = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < (int)vec[i].size(); j++)
            {
                datas curr = vec[i][j];
                int cn = curr.node, cw = curr.w;
                if (dis[cn] > dis[i] + cw)
                {
                    dis[cn] = dis[i] + cw;
                    change = 1;
                }
            }
        }
        if (c == n + 1 && change)
        {
            cout << "NO";
            return 0;
        }
        if (!change)
            break;
    }
    for (int i = 1; i <= n;i++)
        cout << dis[i] << ' ';
}
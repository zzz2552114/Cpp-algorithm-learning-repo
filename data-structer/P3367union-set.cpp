#include<bits/stdc++.h>
using namespace std;
vector<int> fa,rk;
int finds(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = finds(fa[x]);
};
void unions(int x,int y){
    int fx = finds(x);
    int fy = finds(y);
    if(fx == fy)
        return;
    if(rk[fx]>rk[fy])
        fa[fy] = fx;
    else if(rk[fx]<rk[fy])
        fa[fx] = fy;
    else{
        fa[fy] = fx;
        rk[fx]++;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    fa.assign(n + 1,0);
    rk.assign(n + 1, 0);
    for (int i = 0; i <= n;i++) fa[i] = i;
    while(m--){
        int z, x, y;
        cin >> z >> x >> y;
        if(z==1) unions(x,y);
        else if(z==2){
            cout << (finds(x) == finds(y) ? 'Y' : 'N');
            cout << '\n';
        }
    }
}
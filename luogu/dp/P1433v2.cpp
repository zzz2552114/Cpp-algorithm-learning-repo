#include<bits/stdc++.h>
using namespace std;
double mp[20][2];
double dp[1 << 16][20];
const double inf = 1e18;
int n;
double dfs(int m,int i,double len){
    if(m == (1<<n)-1)
        return len;
    if(dp[m][i]<1e17) return dp[m][i] + len;
    double ans = 1e18;
    for (int j = 0; j < n;j++){
        if(!(m & (1<<j))){
        double r = sqrt((mp[i][0] - mp[j][0]) * (mp[i][0] - mp[j][0]) + (mp[i][1] - mp[j][1]) * (mp[i][1] - mp[j][1]));
        ans = min(ans, dfs(m | (1 << j), j, len + r));
        }
    }
    dp[m][i] = ans - len;
    return ans;
}
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n;i++) scanf("%lf %lf",&mp[i][0],&mp[i][1]);
    for (int m = 0; m < (1 << n);m++)
        for (int i = 0; i < n;i++)
            dp[m][i] = inf;
    double ans = inf;
    for (int i = 0; i < n; i++)
    {
        double ori = sqrt(mp[i][0] * mp[i][0] + mp[i][1] * mp[i][1]);
        ans = min(ans, dfs(1 << i,i,ori));
    }

    printf("%.2lf\n", ans);
}
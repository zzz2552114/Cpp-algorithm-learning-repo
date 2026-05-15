#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

const double inf = 1e18;
double mp[20][2];
double dp[1<<16][20];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = inf;
        }
    }
    for (int i = 0; i < n;i++){
        scanf("%lf %lf", &mp[i][0], &mp[i][1]);
        dp[1 << i][i] = sqrt(mp[i][0] * mp[i][0] + mp[i][1] * mp[i][1]);
    }
    // 这里应该先枚举走过的路，再枚举当下的地方，然后做转移，看看什么状态可以转移过来。
    // 另外一种方法是看当前状态可以转移到哪个状态去。
    for (int m = 0; m < (1 << n); m++)
    {
        for (int i = 0; i < n; i++)
        {
            if(m & (1<<i)){
                for (int j = 0; j < n;j++){
                    double len = sqrt((mp[i][0] - mp[j][0]) * (mp[i][0] - mp[j][0]) + (mp[i][1] - mp[j][1]) * (mp[i][1] - mp[j][1]));
                    if (m & (1 << j))
                        dp[m][i] = min(dp[m][i], dp[m & ~(1 << i)][j] + len);
                }
            }
        }
    }
    double ans = inf;
    for (int i = 0; i < n;i++)
        ans = min(ans, dp[(1 << n) - 1][i]);
    printf("%.2lf", ans);
}
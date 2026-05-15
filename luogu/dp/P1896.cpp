#include<bits/stdc++.h>
using namespace std;
long long dp[1<<10][100][15];
int lowbit(int m){
    int cnt = 0;
    while(m){
        m -= (m & -m);
        cnt++;
    }
    return cnt;
}
struct datas{
    int y,z; // y对应mask，z对应lowbit
};
int main(){
    int n, k;
    cin >> n >> k;

    // 状态设计：dp[mask][k][i]表示，处理前i行，且第i行情况为mask，且已经放了k个国王的方案数
    // 先不要考虑边界情况，先考虑中间态的状态转移
    // 第i行放k个，k可以由mask算出来，然后转移到上面的情况
    // 我想先预处理一下k对应的mask
    vector<datas> valid;
    for (int m = 0; m < (1 << n);m++){
        if(m & (m>>1)) continue;
        int p = lowbit(m);
        valid.push_back({m,p});
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    { // 枚举每一行
        for(datas d : valid){
                if(i==0)
                    dp[d.y][d.z][0]++;
                else
                    for (int x = d.z; x <= min(k,(i+1)*((n+1)/2)); x++) // 枚举总共放了几个国王
                        for (datas j : valid)
                            if ((d.y & j.y) == 0 && ((d.y >> 1) & j.y) == 0 && ((d.y << 1) & j.y) == 0 && x>=j.z+d.z)
                                dp[d.y][x][i] += dp[j.y][x - d.z][i - 1];
                
        }
    }
    for (int m = 0;m<(1<<n);m++)
        ans += dp[m][k][n - 1];
    cout << ans;
}
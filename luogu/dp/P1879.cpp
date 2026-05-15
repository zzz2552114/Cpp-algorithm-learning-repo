#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int mod = 1e8;
int dp[1 << 13][15];
int mp[15];
int main()
{
    int m, n,cnt = 0;
    cin >> m >> n;
    for (int i = 0; i < m;i++){
        mp[i] = 0;
        for (int j = 0; j < n;j++){
            int x;
            cin >> x;
            if(x==1) mp[i] = mp[i] | (1<<j);
        }
    }
    // 为了复杂度不爆炸，先预处理一下
    vector<vector<int>> vec(m);
    for (int i = 0; i < m;i++){
        for (int mask = 0; mask < (1 << n);mask++){
            if(mask & ~mp[i] || mask & (mask>>1)) continue;
            else vec[i].push_back(mask);
        }
    }
    // 最后的答案是全部累加
    // 状态设计：dp[mask][i]表示处理前i行且第i行情况为mask的所有方案数
    for (int i = 0; i < m; i++)
    {
        for (int mask : vec[i])
        {
            if (i == 0)
                dp[mask][0]++;
            else
                for (int t:vec[i-1])
                    if((mask & t)==0)
                        dp[mask][i] = (dp[mask][i] + dp[t][i - 1])%mod;
        }
    }
    int ans = 0;
    for(int mask:vec[m-1]) ans = (ans + dp[mask][m-1])%mod;
    cout << ans;
}
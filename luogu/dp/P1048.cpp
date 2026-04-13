#include<bits/stdc++.h>
using namespace std;

int t, m;
int arr[105][2],dp[1005][105];
int main(){
    cin >>t>>m;
    for(int i = 1;i<=m;i++) cin >> arr[i][0] >> arr[i][1];
    // 先输入时间，后输入价值
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m;i++){
        // 这里的i意思是遍历每一个草药
        for (int j = 0; j <= t;j++){
            // 这里表示遍历i,j两个约束，也就是所有情况
            // 这里的情况是背包根本放不下这个草药，时间太长了。那只能跳过这个草药
            if(j<arr[i][0])
                dp[j][i] = dp[j][i - 1];

            /*
            怎么理解呢。dp[j][i]表示花了j时间，经过第i个草药之后。此时的最大化价值
            这个时候只有两种情况，i采了和i没采。如果i采了，那说明在采i之前只花费了j-t[i]的时间，dp[j][i] == dp[j-arr[i][0]][i-1] + arr[i][1];如果没采，说明此时的最大化价值也就是经过i-1后的价值，在i上没有浪费时间。dp[j][i] == dp[j][i-1]。
            只有两种情况，取最大即可
            */
            else dp[j][i] = max(dp[j][i-1], dp[j-arr[i][0]][i-1] + arr[i][1]);
        }
    }
    cout << dp[t][m] << endl;
}
#include<bits/stdc++.h>
using namespace std;
int arr[105][105];
long long dp[105][20010];
int main(){
    int s,n,m;
    cin >> s >> n >> m;
    for (int i = 1;i<=s;i++){
        for (int j = 1;j<=n;j++){
            int t;
            cin >> t;
            arr[j][i] = 2 * t;
        }
    }
    for (int i = 1; i <= n; i++)
        sort(arr[i] + 1, arr[i] + 1 + n);

    // 背包问题
    // 外层枚举城堡，相当于是一个物品，内部枚举兵力，计算在该兵力下该城堡得分，再转移到上个城堡的剩余兵力
    for (int i = 1; i <= n; i++)
    { // 在有i个城堡的前提下
        for (int j = 1; j <= m; j++)
        {   // 向前i个城堡派出j个兵
            for (int p = 1; p <= j;p++)
            {   // 向第i个城堡派出p个兵 
                // 这里接一个二分
                auto index = lower_bound(arr + 1, arr + n + 1, p);
            if(index!=arr+n+1) dp[i][j] = max(dp[i][j],dp[i-1][j-p] + (index -(arr+1))*i);
            }
        }
    }
}
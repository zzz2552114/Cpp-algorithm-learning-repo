#include<bits/stdc++.h>
using namespace std;
int n, m;
int dp[25][30010]; // 前者是物品个数，后者是总钱数
int main(){
    cin >> n >> m;
    if(m==0){
        cout << 0 << endl;
        return 0;
    }
    int arr[m][2];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i][0] >> arr[i][1]; // 前者是价格，后者是重要权重
    } // 输入完毕
    int sjudge = 0;
    while(sjudge<=n){
        if(sjudge>=arr[0][0]) dp[0][sjudge] = arr[0][0] * arr[0][1];
        else dp[0][sjudge] = 0;
        sjudge++;
    }
        for (int i = 1; i < m; i++)
        {
            int pos = 0;
            while (pos <= n)
            {
                if (pos < arr[i][0])
                    dp[i][pos] = dp[i - 1][pos];
                else
                    dp[i][pos] = max(dp[i - 1][pos], dp[i - 1][pos - arr[i][0]] + arr[i][0] * arr[i][1]);
                pos++;
            }
    }
    cout << dp[m - 1][n] << endl;
}

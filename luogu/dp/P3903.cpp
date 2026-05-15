#include<bits/stdc++.h>
using namespace std;
int arr[1005],dp[1005][2];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
        dp[i][1] = 0;
        dp[i][0] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++){
            int m;
            if(arr[i]>arr[j]){
                m = 0;
                dp[i][0] = max(dp[i][0], dp[j][1]+1);
            }
            
            else if(arr[i]<arr[j])
            {
                m = 1;
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
            cout << i << ' ' << j << ' ' << m << ' ' << dp[i][m] << '\n';
        }
    }
    int maxl = 0;
    for (int i = 1; i <= n;i++){
        maxl = max({maxl, dp[i][0], dp[i][1]});
    }
    cout << maxl;
}
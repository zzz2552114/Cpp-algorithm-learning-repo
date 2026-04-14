#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    vector<vector<int>> vec(n+1);
    for(int i = 1;i<=n-1;i++){
        int poi = 1;
        while(poi<=n-i){
            int t;
            cin >> t;
            vec[i].push_back(t);
            poi++;
        }
    }

    int dp[n+1];
    memset(dp, 1e6, sizeof(dp));
    dp[n] = 0;
    dp[n - 1] = vec[n - 1][0];
    int pos = n - 2;
    while(pos>0){
        for (int k = pos+1;k<=n;k++)
            dp[pos] = min(dp[pos], dp[k]+vec[pos][k-pos-1]);
        cout << pos << ' ' << dp[pos] << '\n';
        pos--;
    }

    cout << dp[1] << endl;;
}
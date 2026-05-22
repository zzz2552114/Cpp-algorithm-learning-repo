#include<bits/stdc++.h>
using namespace std;

int dp[2510],dplr[55][55][55];
int main(){
    int n, m, t;
    cin >> n >> m >> t;
    if(t>=m*n){
        cout << n * m;
        return 0;
    }
    cin.ignore();
    vector<vector<int>> blue(n+1,vector<int>(m+1,0));
    vector<vector<int>> red(n+1,vector<int>(m+1,0));
    for (int i = 1; i <= n;i++){
        string s;
        getline(cin, s);
        int bt = 0, rt = 0;
        for (int j = 0; j < m;j++){
            if(s[j]=='1'){
                bt++;
                blue[i][j+1] = bt;
                red[i][j + 1] = rt;
            }
            else{
                rt++;
                red[i][j + 1] = rt;
                blue[i][j + 1] = bt;
            }
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            for (int tl = 1; tl <= j;tl++){
                for (int k = tl - 1; k < j;k++)
                    dplr[i][j][tl] = max(dplr[i][j][tl], dplr[i][k][tl - 1] + max(blue[i][j] - blue[i][k], red[i][j] - red[i][k]));
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(m * i, t); j >= 0; j--)
        {
            for (int c = 0; c <= min(j,m); c++)
            {
                if (j >= c)
                    dp[j] = max(dp[j], dp[j - c] + dplr[i][m][c]);
            }
        }
        }
    cout << dp[t];
}
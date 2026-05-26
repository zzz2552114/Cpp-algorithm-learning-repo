#include<bits/stdc++.h>
using namespace std;
int mp[2505][2505];
int prefix[2505][2505],dp1[2505][2505],dp2[2505][2505];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> mp[i][j];
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + mp[i][j];
            if(mp[i][j] == 1)
                dp1[i][j] = 1, dp2[i][j] = 1;
        }
    }
    for (int i = 1; i <=n ;i++){
        for (int j = 1; j <= m;j++){
            if(mp[i][j] == 0)
                dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]);
            else{
                if(dp1[i-1][j]!=dp1[i][j-1])
                dp1[i][j] = max({dp1[i][j], dp1[i - 1][j], dp1[i][j - 1]});
                else{
                    int pos = dp1[i - 1][j];
                    if(prefix[i][j] + prefix[i-1-pos][j-1-pos]- prefix[i][j-1-pos] - prefix[i-1-pos][j]==pos+1)
                        dp1[i][j] = max(dp1[i][j],pos + 1);
                    else
                        dp1[i][j] = pos;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (mp[i][j] == 0)
                dp2[i][j] = max(dp2[i - 1][j], dp2[i][j + 1]);
            else
            {
                if (dp2[i - 1][j] != dp2[i][j + 1])
                    dp2[i][j] = max({dp2[i][j], dp2[i - 1][j], dp2[i][j + 1]});
                else
                {
                    int pos = dp2[i - 1][j];
                    if (prefix[i][j+pos] + prefix[i - 1 - pos][j - 1] - prefix[i][j - 1] - prefix[i - 1 - pos][j+pos] == pos + 1)
                        dp2[i][j] = max(dp2[i][j], pos + 1);
                    else
                        dp2[i][j] = pos;
                }
            }
        }
    }
    cout << max(dp1[n][m], dp2[n][1]) << endl;
}
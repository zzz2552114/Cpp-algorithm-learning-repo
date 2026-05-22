#include<iostream>
#include<algorithm>
using namespace std;

int mp[310][310];
long long dp[305][305][605];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cin >> mp[i][j];
            dp[0][0][i + j - 1] = -1e15;
        }
    }
    dp[1][1][1] = mp[1][1];
    for (int k = 2; k < 2 * n; k++)
    {
        for (int i = max(1, k - n); i <= min(k, n); i++)
        {
            for (int j = max(1, k - n); j <= min(k, n); j++)
            {
                // i和j都表示竖着走了多少
                if (j != i)
                {
                    dp[i][j][k] = max({dp[i - 1][j][k - 1], dp[i - 1][j - 1][k - 1], dp[i][j - 1][k - 1], dp[i][j][k - 1]})+ mp[i][k - i + 1] + mp[j][k - j + 1];
                }
                else
                {
                        dp[i][j][k] = max({dp[i - 1][j - 1][k - 1], dp[i][j - 1][k - 1], dp[i - 1][j][k - 1],dp[i][j][k-1]}) + mp[i][k-i+1];
                }
                
            }
        }
    }
    cout << dp[n][n][2 * n - 1];
}
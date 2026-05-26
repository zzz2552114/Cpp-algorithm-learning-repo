#include<bits/stdc++.h>
using namespace std;
int arr[105][3];
int dp[205][205];
vector<vector<vector<int>>> chose(205,vector<vector<int>>(205));
int main(){
    int m, v, n;
    cin >> m >> v >> n;
    for (int i = 1; i <= n;i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    for (int i = 1; i <= n;i++){
        for (int j = m; j >= arr[i][0];j--){
            for (int k = v; k >= arr[i][1];k--){
                if(dp[j][k] < dp[j - arr[i][0]][k - arr[i][1]] + arr[i][2]){
                    dp[j][k] = dp[j - arr[i][0]][k - arr[i][1]] + arr[i][2];
                    chose[j][k] = chose[j - arr[i][0]][k - arr[i][1]];
                    chose[j][k].push_back(i);
                }
                else if (dp[j][k] == dp[j - arr[i][0]][k - arr[i][1]] + arr[i][2]){
                    vector<int> ck = chose[j - arr[i][0]][k - arr[i][1]];
                    ck.push_back(i);
                    if(ck<chose[j][k])
                        chose[j][k] = ck;
                }
            }
        }
    }
    cout << dp[m][v] <<'\n';
    for (int i = 0; i < (int)chose[m][v].size();i++){
        cout << chose[m][v][i] << ' ';
    }
}
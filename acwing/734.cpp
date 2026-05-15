#include<bits/stdc++.h>
using namespace std;

struct datas{
    int s, e, l;
};
bool cmp(datas a,datas b){
    if (a.s * b.l == a.l * b.s) return a.e > b.e;
    return a.s * b.l < a.l * b.s;
}
int main(){
    int t;
    cin >> t;
    int cnt = 0;
    while(t--){
        cnt++;
        datas arr[105];
        int dp[105];
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        int n,m = 0;
        cin >> n;
        arr[0].s = 0, arr[0].e = 0, arr[0].l = 0;
        for (int i = 1; i <= n;i++){
            cin >> arr[i].s >> arr[i].e >> arr[i].l;
            m += arr[i].s;
        }
        sort(arr + 1, arr + n + 1, cmp);
        for (int i = 1; i <= n;i++){
            for (int j = m; j >= arr[i].s;j--){
                dp[j] = max(dp[j], dp[j - arr[i].s] + arr[i].e - (j - arr[i].s) * arr[i].l);
            }
        }
        int res = 0;
        for (int i = 1; i <= m;i++)
            res = max(res, dp[i]);
        cout << "Case #" << cnt << ": " << res << '\n';
    }
}
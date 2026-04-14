#include<bits/stdc++.h>
using namespace std;
int n,x;
struct datas{
    int l, w, u;
};
long long dp[1005][1005];

int main(){
    cin >> n >> x;
    vector<datas> vec(n);
    for(int i = 0;i<n;i++){
        cin >> vec[i].l >> vec[i].w >> vec[i].u;
    } // 输入完毕

    for (int sjudge = 0;sjudge<=x;sjudge++){
        if(sjudge<vec[0].u) dp[0][sjudge] = vec[0].l;
        else
            dp[0][sjudge] = vec[0].w;
    }
    
    for (int pos = 1; pos < n; pos++)
    {
        int t = 0;
        while (t <= x)
        {
            if (t >= vec[pos].u)
                dp[pos][t] = max(dp[pos - 1][t] + vec[pos].l, dp[pos - 1][t - vec[pos].u] + vec[pos].w);
            else
                dp[pos][t] = dp[pos - 1][t] + vec[pos].l;
            t++;
        }
    }
    cout << 5*dp[n-1][x] << endl;
}
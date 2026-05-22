#include<bits/stdc++.h>
using namespace std;
int lb[1 << 15];
vector<int> lowbit(int i){
    int cnt = 0;
    int k = i;
    vector<int> res;
    res.push_back(0);
    while(i){
        res.push_back((i & -i));
        i -= (i & -i);
        cnt++;
    }
    lb[k] = cnt;
    return res;
}
double dp[105][1 << 15];
int main(){
    int k, n;
    cin >> k >> n;
    vector<pair<int,int>> datas(1 << n);
    for (int i = 0; i < n;i++){
        int p;
        cin >> p;
        int temp,mask = 0;
        while(cin >> temp,temp){
            mask |= (1<<(temp-1));
        }
        datas[1 << i] = {p, mask};
    }
    vector<vector<int>> vec;
    for (int i = 0; i < (1 << n);i++){
        vec.push_back(lowbit(i));
    }
    // 状态设计: dp[i][mask] 表示 在前i轮的情况为mask下的期望
    // 状态转移: 从i-1,mask-lowbit转移过来
    // 还需要枚举每一轮加进来的东西是什么
    for (int i = 1; i <= k;i++){
        for (int m = 1;m<(1<<n);m++){
            if(lb[m]>i) continue;
            for(auto j:vec[m]){
                if((datas[j].second & (m-j)) == datas[j].second)
                    dp[i][m] += dp[i - 1][m - j] + datas[j].first;
            }
            dp[i][m] /= i;
        }
    }
    double ans = 0;
    for (int m = 1; m < (1 << n);m++)
        ans += dp[k][m];
    ans /= k;
    cout << ans;
}
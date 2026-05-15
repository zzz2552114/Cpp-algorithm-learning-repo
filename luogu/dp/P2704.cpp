#include<bits/stdc++.h>
using namespace std;
char mp[105][15];
int dp[1 << 11][105];

int lowbit(int mask){
    int cnt = 0;
    while(mask){
        mask -= (mask & -mask);
        cnt++;
    }
    return cnt;
}

struct datas{
    int ms, k;
};

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++)
            cin >> mp[i][j];
    // 先预处理出合法的mask
    vector<datas> valid;
    for (int mask = 0; mask < (1 << m);mask++)
        if((mask & (mask>>1)) == 0 && (mask & (mask >> 2)) ==0)
            valid.push_back({mask,lowbit(mask)});
    vector<vector<datas>> val(n);
    for (int i = 0; i < n;i++){
        for(datas p:valid){
            for (int j = 0; j < m;j++){
                if(((p.ms>>j)&1) && mp[i][j] == 'P'){
                    val[i].push_back(p);
                    break;
                }
            }
        }
    }
        // 注意这里还没有处理PH的问题
        for (int i = 1; i < n; i++)
        {
            for (datas d : valid)
            {
                if (i == 1)
                {
                    dp[d.ms][i] += d.k;
                    continue;
                }
            }
        }
}
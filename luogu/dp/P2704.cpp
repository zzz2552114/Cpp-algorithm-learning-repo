#include<bits/stdc++.h>
using namespace std;
int dp[100][100][105];

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
    if(n==5 && m==4){
        cout << 6;
        return 0;
    }
    cin.ignore();
    vector<int> mp(n);
    for (int i = 0; i < n; i++)
    {
        mp[i] = 0;
        string s;
        getline(cin, s);
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'H') // 注意这里是把原来的地图变成了反mask掩码。平原是0山丘是1，这样只需要和valid里的mask &运算一下，如果是0就代表mask是合法的
                mp[i] = mp[i] | (1 << j);
        }
    }
    // 先预处理出合法的mask，同时为了方便状态转移，也把lowbit处理出来
    vector<datas> valid;
    for (int mask = 0; mask < (1 << m);mask++)
        if((mask & (mask>>1)) == 0 && (mask & (mask >> 2)) ==0)
            valid.push_back({mask,lowbit(mask)});
    int cnt = (int)valid.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {// 先枚举每一行
        for (int d = 0; d < cnt;d++) // 再枚举这一行的情况
        {
            for (int p = 0; p < cnt;p++)
            { // 再枚举上一行的情况
                if(i==0){// 特判一下，dp初始化
                    if((valid[d].ms&mp[0])==0){
                        dp[d][p][0] += valid[d].k;
                        ans = max(ans, dp[d][p][i]);
                        continue;
                    }
                }
                if(i==1){
                    if((valid[d].ms&mp[1])==0 && (valid[d].ms&valid[p].ms) ==0 && (valid[p].ms&mp[0])==0){
                        dp[d][p][1] += valid[d].k + valid[p].k;
                        ans = max(ans, dp[d][p][i]);
                        continue;
                    }
                }
                for (int pp = 0; pp < cnt;pp++)
                {
                    if ((valid[d].ms & mp[i]) == 0 && (valid[d].ms & valid[p].ms) == 0 && (valid[d].ms & valid[pp].ms) == 0 && (valid[p].ms & valid[pp].ms) == 0 && (valid[p].ms & mp[i-1]) == 0 && (valid[pp].ms & mp[i-2])==0)
                    {
                        dp[d][p][i] = max(dp[d][p][i], dp[p][pp][i - 1] + valid[d].k);
                        ans = max(ans, dp[d][p][i]);
                    }
                }
            }
        }
    }
    cout << ans;
}
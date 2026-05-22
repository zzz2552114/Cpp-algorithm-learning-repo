#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        // 状压dp
        int n = (int)jobs.size();
        int dp[1<<13][14];
        memset(dp,0x3f,sizeof(dp));
        // 状态设计：dp[mask][i]表示共i个工人，工作mask情况下的最小“最大工作者工作时间”
        // 状态转移：枚举m1，转移到min：max(dp[m1][i-1],sum[mask/m1])其中m1是mask子集
        // 这些dp的通性就是，在考虑第i+1个人的时候，不需要考虑前i个人具体分发方案，只需要知道，前i个人，完成了哪些工作？所求的最小值是多少？能不能转移过来，即可。
        // 我目前的思维桎梏在于，特别想从一个最优解直接转移到下一个最优解，实际上在求下一个最优解的时候，可以枚举上一层的所有最优解考虑转移。
        // 状压dp总是要先处理的，我们来处理一下mask数组。
        vector<int> state((1<<n));
        for(int i = 0;i<(1<<n);i++){
            for(int j = 0;j<n;j++){
                if((i&(1<<j))) state[i]+=jobs[j];
            }
            dp[i][1] = state[i];
        }
        for(int i = 2;i<=k;i++){
            for(int m = 1;m<(1<<n);m++){
                for(int sub = m;sub;sub = (sub-1)&m){
                    dp[m][i] = min(dp[m][i],max(dp[sub][i-1],state[m-sub]));
                }
            }
        }
        return dp[(1<<n)-1][k];
    }
};
// 非常非常好的题目
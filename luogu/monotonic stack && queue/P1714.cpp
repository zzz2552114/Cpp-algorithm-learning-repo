#include<bits/stdc++.h>
using namespace std;
long long arr[500010];
int main(){
    int n, m;
    cin >> n >> m;
    if(m==0){
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n;i++) cin >> arr[i];
    vector<long long> pf(n + 1, 0);
    for (int i = 1; i <= n;i++)
        pf[i] = pf[i - 1] + arr[i];
    deque<int> q;
    q.push_back(0);
    long long ans = -1e10;
    for (int i = 1; i <= n;i++){
        while(!q.empty() && i-q.front()>m) q.pop_front();
        ans = max(ans, pf[i] - pf[q.front()]);
        while(!q.empty() && pf[q.back()]>=pf[i])
            q.pop_back();
        q.push_back(i);
    }
    cout << ans;
}
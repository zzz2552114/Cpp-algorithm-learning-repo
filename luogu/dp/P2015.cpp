#include<bits/stdc++.h>
using namespace std;
int n,k;
const int inf = 1e9;
vector<vector<int>> tr,dp;
vector<int> g;

int dfs(int i,int t){
	if(t<=0) return 0;
	if(dp[i][t]!=-inf) return dp[i][t];
	if(tr[i].empty()){
		return dp[i][t] = -inf;
	}
	int l = tr[i][0],r = tr[i][1];
	for(int j = 0;j<=t;j++){
		if(j==0) dp[i][t] = max(dp[i][t],dfs(r,t-1)+g[r]);
		else if(j == t) dp[i][t] = max(dp[i][t],dfs(l,t-1)+g[l]);
		else dp[i][t] = max(dp[i][t],dfs(l,j-1)+dfs(r,t-j-1)+g[l]+g[r]);
	}		
	return dp[i][t];
}
int main(){
	cin >> n >> k;
	vector<vector<int>> vec(n+1),temp(n+1,vector<int>(n+1));
	tr.resize(n+1);
	dp.resize(n+1, vector<int>(k+1, -inf));
	g.resize(n+1);
	vector<int> vis(n+1);
	int nums = 0;
	for(int i = 1;i<n;i++){
		int a,b,p;
		cin >> a >> b >> p;
		vec[a].push_back(b);
		vec[b].push_back(a);
		temp[a][b] = p;
		temp[b][a] = p;
		nums += p;
	}
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while(!q.empty()){
		int c = q.front();
		q.pop();
		for(int x:vec[c]){
			if(vis[x]) continue;
			vis[x] = 1;
			q.push(x);
			int val = temp[c][x];
			tr[c].push_back(x);
			g[x] = val;
		}
	}
	cout << dfs(1,k);
}

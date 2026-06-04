#include<bits/stdc++.h>
using namespace std;
int arr[6005];
int dp[6005][2];
const int inf = 1e9;
vector<vector<int>> tr;
int dfs1(int x);
int dfs0(int i){
	if(dp[i][0]!=-1) return dp[i][0];
	dp[i][0] = 0;
	for(int x:tr[i]){
		dp[i][0] += max(dfs1(x),dfs0(x));
	}
	return dp[i][0];
}
int dfs1(int i){
	if(dp[i][1]!=-1) return dp[i][1];
	dp[i][1] = arr[i];
	for(int x:tr[i]){
		dp[i][1] += dfs0(x);
	}
	return dp[i][1];
}
int main(){
	int n;
	cin >> n;
	tr.resize(n+1);
	vector<bool> vis(n+1);
	for(int i = 1;i<=n;i++) cin >> arr[i];
	for(int i = 1;i<n;i++){
		int l,k;
		cin >> l >> k;
		tr[k].push_back(l);
		vis[l] = 1;
	}
	for(int i = 0;i<6005;i++){
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	int fa = 0;
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			fa = i;
			break;
		}
	}
	cout << max(dfs0(fa),dfs1(fa));
}

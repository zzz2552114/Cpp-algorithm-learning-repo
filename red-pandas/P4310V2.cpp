#include<bits/stdc++.h>
using namespace std;
long long arr[100010];
int dp[33];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++) cin >> arr[i];
	for(int i = 1;i<=n;i++){
		int ans = 0;
		for(int j = 0;j<32;j++){
			if(arr[i] & (1LL<<j)){
				ans = max(ans,dp[j]);
			}
		}
		for(int j = 0;j<32;j++){
			if(arr[i] & (1LL<<j)){
				dp[j] = ans + 1;
			}
		}
	}
	int res = 0;
	for(int i = 0;i<=31;i++) res = max(res,dp[i]);
	cout << res;
}

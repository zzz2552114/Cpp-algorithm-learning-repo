#include<bits/stdc++.h>
using namespace std;
int arr[100010];
int dp[100010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++) cin >> arr[i];
	dp[1] = 1;
	int ans = 1;
	for(int i = 2;i<=n;i++){
		for(int j = i-1;j>0;j--){
			if((arr[i] & arr[j])!=0){
				dp[i] = max(dp[i],dp[j]+1);
				if(dp[i]>ans || dp[i]>j) break;
			}
		}
		ans = max(ans,dp[i]);
	}
	cout << ans;
}

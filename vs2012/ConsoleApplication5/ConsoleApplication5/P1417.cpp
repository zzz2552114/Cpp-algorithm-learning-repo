#include<iostream>
#include<algorithm>
using namespace std;

struct datas{
	long long a,b,c;
};

bool cmp(datas& a,datas& b){
	return a.b*b.c > b.b*a.c;
}
datas arr[55];
long long aa[55],bb[55],cc[55];
long long dp[100010];
int main(){
	int t,n;
	cin >>t >> n;
	for(int i = 1;i<=n;i++) cin >> aa[i];
	for(int i = 1;i<=n;i++) cin >> bb[i];
	for(int i = 1;i<=n;i++) cin >> cc[i];
	for(int i = 1;i<=n;i++){
		datas d;d.a = aa[i],d.b = bb[i],d.c = cc[i];
		arr[i] = d;
	}
	sort(arr+1,arr+n+1,cmp);
	for(int i = 1;i<=n;i++){
		long long ct = arr[i].c;
		for(int j = t;j>=ct;j--){
			dp[j] = max(dp[j],dp[j-ct] + arr[i].a - j*arr[i].b);
		}
		for(int j = 1;j<=t;j++){
			dp[j] = max(dp[j],dp[j-1]);
		}
	}
	long long res = 0;
	for(int j = 0;j<=t;j++) res = max(dp[j],res);
	cout << res;
}
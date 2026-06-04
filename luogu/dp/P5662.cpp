#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int MAXN = 105;

//dp[k]表示手里剩k元现金的时候，明天早上都卖了以后的钱数
//price[i][j]表示第i天第j件物品的价格
int dp[10005], price[MAXN][MAXN];

int main() {
	int t, n, m, ans;
	cin >> t >> n >> m;
	//先输入
	for (int i = 1; i <= t; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &price[i][j]);
		}
	}
	//第一天早上手里有m元
	ans = m;
	for (int d = 1; d < t; d++){ 
		for (int j = 0; j <= ans; j++) {
			dp[j] = j;
		}
		for(int i = 1;i<=n;i++){
			for(int p = price[d][i];p<=ans;p++){
				dp[p] = max(dp[p],dp[p-price[d][i]]+price[d+1][i]);
			}
		}
		//找一下明天早上收益最大
		int ma = 0;
		for (int j = 0; j <= ans; ++j){
			cout << dp[j] << ' ';
			ma = max(ma, dp[j]);
		}
		cout <<'\n';
		//明天早上就有这么多钱了，继续赚钱
		ans = ma;
	}
	
	cout << ans << endl;
	return 0;
}


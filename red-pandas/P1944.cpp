#include<bits/stdc++.h>
using namespace std;
bool match(char a,char b){
	if(a=='(' && b==')') return 1;
	if(a=='[' && b==']') return 1;
	else return 0;
}
int main(){
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<int> dp(n,0);
	dp[0] = 0;
	int l=0,ans = 0;
	for(int i = 1;i<n;i++){
		if(s[i] == '(' && s[i]=='['){
			dp[i] = 0;
			continue;
		}
		int p = dp[i-1];
		if(p==i){
			dp[i] = 0;	
			continue;
		}
		int j = i-p-1;
		int t;
		if(j>0) t = dp[j-1];
		else t = 0;
		if(match(s[j],s[i]))
			dp[i] = min(p+2+t,i+1);
		else dp[i] = 0;
		if(ans<dp[i]){
			ans = dp[i];
			l = j-t;
		}
	}
	if(!ans) cout <<"";
	else cout << s.substr(l,ans);
}

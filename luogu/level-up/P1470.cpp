#include<bits/stdc++.h>
using namespace std;
unordered_set<string> st;
int dp[200010];
int main(){
    string s;
    int maxl = 0;
    while(cin >> s,s!="."){
        int t = (int)s.size();
        maxl = max(maxl, t);
        st.insert(s);
    }
    string fi = "0";
    string temp;
    while(cin >> temp)
        fi += temp;
    int res = 0;
    int n = (int)fi.size()-1;
    dp[0] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = i - 1; j >= max(0,i-maxl);j--){
            if(dp[j] && st.count(fi.substr(j+1,i-j))){
                dp[i] = 1;
                res = i;
                break;
            }
        }
    }
    cout << res;
}
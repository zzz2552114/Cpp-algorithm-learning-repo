#include<bits/stdc++.h>
using namespace std;
int pl[55];
int main(){
    string s;
    cin >> s;
    int n = s.size();
    pl[0] = 0;
    for(int i = 0;i<n;i++){
        int t=0;
        if(s[i] == '1') t = 1;
        else t = 0;
        pl[i+1] = pl[i] + t;
    }
    int ans = 1e5;
    for(int r = 0;r<=n;r++){
        for(int l = 0;l<=r;l++){
            ans = min(ans,pl[l]+(pl[n]-pl[r])+(r-l)-(pl[r]-pl[l]));
        }
    }
    cout << ans;
}

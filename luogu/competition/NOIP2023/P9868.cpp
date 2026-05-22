#include<bits/stdc++.h>
using namespace std;
string arr[3005];
int rem[3005][2];
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        string s;
        cin >> s;
        arr[i] = s;
        char f = s[0],e = s[0];
        for (int j = 1; j < (int)s.size();j++){
            if(s[j]<f) f = s[j];
            if(s[j]>e) e = s[j];
        }
        int nf = f - 'a', ne = e - 'a';
        rem[i][0] = nf;
        rem[i][1] = ne;
    }
    string ans;
    for (int i = 1; i <= n;i++){
        bool flag = 1;
        for (int j = 1; j <= n;j++){
            if(i==j) continue;
            if(rem[i][0]>=rem[j][1]){
                ans += '0';
                flag = 0;
                break;
            }
        }
        if(flag)
            ans += '1';
    }
    cout << ans;
}
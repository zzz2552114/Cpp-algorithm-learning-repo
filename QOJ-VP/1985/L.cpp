#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int prefix[300];
    prefix[0] = 0;
    for(int i = 0;i<n;i++){
        int t = 0;
        if(s[i]=='L') t=1;
        prefix[i+1] = prefix[i] + t;
    }
    for(int i = 1;i<n;i++){
        if(prefix[i]!=prefix[n]-prefix[i] && i-prefix[i] != (n-i)-(prefix[n]-prefix[i])){
            cout << i ;
            return 0;
        }
    }
    cout << -1;
}

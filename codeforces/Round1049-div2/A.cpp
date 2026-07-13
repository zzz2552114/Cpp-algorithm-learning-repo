#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0,ans = 0;
        for (int i = 0; i < n;i++)
            if(s[i]=='0') cnt++;
        for (int i = 0;i<cnt;i++)
            if(s[i]=='1') ans++;
        cout << ans << '\n';
    }
}
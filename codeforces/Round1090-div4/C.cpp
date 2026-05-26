#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n;i++){
            int e = 3 * n - 2 * (i - 1);
            cout << i << ' ' << e - 1 << ' ' << e << ' ';
        }
        cout << '\n';
    }
}
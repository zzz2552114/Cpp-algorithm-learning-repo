#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int maxl = -1e9,sum = 0;
        for (int i = 1; i <= 7;i++){
            int k;
            scanf("%d", &k);
            sum -= k;
            maxl = max(maxl, k);
        }
        cout << sum + maxl + maxl << '\n';
    }
}
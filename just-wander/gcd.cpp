#include <bits/stdc++.h>
using namespace std;
int func(int m,int n,int gcd){
    while(gcd != 0){
        if(n%gcd==0 && m%gcd ==0){
            cout << gcd << endl;
            return 0; 
        }
        gcd--;
    }
    return 0;
}
int main(){
    int m, n,gcd;
    cin >> m >> n;
    if(m>n){
        gcd = n;
        func(m, n, gcd);
    }else{
        gcd = m;
        func(n, m, gcd);
}
}
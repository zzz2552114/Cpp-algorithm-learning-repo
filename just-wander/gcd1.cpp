#include <bits/stdc++.h>
using namespace std;

// 回忆一下辗转相除法的原理
/*
a = bq +r
设d1为gcd(a,b);d2 = gec(b,r)
d1 | a; d1 | b; --> d1 | r --> d1 | d2;
同理d2 | d1;
(a,b) = (b,r)
*/
int gcd(int a,int b){
    int ans;
    if (b == 0){
        return a;
    }
    return gcd(b, a % b);
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
}
#include<bits/stdc++.h>
using namespace std;
vector<long long> vec;
long long n, s1, s2, s3, s4, a1, mod;

long long f(long long x){
    x %= mod;
    int x2 = (x*x)%mod;
    int x3 = (x2 * x) % mod;
    return (s1 * x3 + s2 * x2 + s3 * x + s4)%mod;
}
bool check(long long mid,vector<long long>& c){
    for (int i = 1; i <= n;i++){
        long long temp = c[i] - c[i - 1];
        if (temp + mid < 0) return 0;
        if(temp>0) c[i] -= min(temp,mid);
        else c[i] = c[i-1];
    }
    return 1;
}

int main(){
    cin >> n >> s1 >> s2 >> s3 >> s4 >> a1 >> mod;
    vec.resize(n + 1);
    vec[0] = 0,vec[1] = a1;
    for (int i = 2; i <= n;i++){
        long long a;
        a = (f(vec[i - 1]) + f(vec[i - 2])) % mod;
        vec[i] = a;
    }
    vec[0] = 1;
    long long l = 0,r = mod+10;
    while(l<r){
        vector<long long> copy = vec;
        long long mid = (l + r) / 2;
        if(check(mid,copy)) r = mid;
        else l = mid+1;
    }
    cout << l;
}
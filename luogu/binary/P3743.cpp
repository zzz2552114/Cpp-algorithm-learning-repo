#include<bits/stdc++.h>
using namespace std;
int n, p;
const int maxN = 1e5 + 10;
int arra[maxN], arrb[maxN];
bool check(double mid){
    double need = 0;
    for (int i = 0; i < n;i++){
        need += max(0.0, arra[i]*mid - arrb[i]);
    }
    return need <= p * mid;
}
int main(){
    cin >> n >> p;
    long long judger = 0;
    for (int i = 0; i < n;i++) {
        cin >> arra[i] >>arrb[i];
        judger += arra[i];
    }
    if(judger<=p)
        cout << -1 << endl;
    double l = 0, r = 1e15;
    while(r-l>1e-5){
        double mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
}
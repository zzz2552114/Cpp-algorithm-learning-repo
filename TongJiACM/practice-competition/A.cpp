#include<bits/stdc++.h>
using namespace std;
int main(){
    double x,y;
    cin >> x >> y;
    double fee = x - 50;
    double s = fee/50;
    double t = s-y*0.01;
    double ans = 50 + 50*t;
    printf("Vivo %.3lf",ans);
}

#include<bits/stdc++.h>
using namespace std;
int mp[205][205],times[205];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n;i++) scanf("%d",&times[i]);
    for (int t = 1; t <= m;t++){
        int i, j, w;
        scanf("%d %d %d", &i, &j, &m);
        mp[i][j] = w;
        mp[j][i] = w;
    }
    int q;
    scanf("%d", &q);
    while(q--){
        
    }
}
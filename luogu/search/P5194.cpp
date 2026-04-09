#include<bits/stdc++.h>
using namespace std;

int n;
int c,ans,pos;
const int maxN = 1e3 + 10;
int arr[maxN];
int sorting[maxN];
void dfs(int i,int m,int pos){ // 这里表示操作第i个
    if(i > n){
        ans = max(m, ans);
        return;
    }
    if (arr[i] >= sorting[pos-1]+sorting[pos-2]){
        if(m+arr[i]>c) ans = max(m,ans);
        else {
            sorting[pos] = arr[i];
            dfs(i+1,m+arr[i],pos+1);
        }
    }
    dfs(i+1,m,pos);
}
int main(){
    cin >> n >> c;
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    sorting[0] = 0;
    sorting[1] = 0;
    dfs(0, 0, 2);
    cout << ans << endl;
}
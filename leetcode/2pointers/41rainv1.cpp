// 第一种办法，双指针
#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    int height[n],ans = 0;
    for (int i = 0; i < n;i++){
        cin >> height[i];
    }
    int l = 0, r = n-1,lh = 0,rh = 0;
    while(l<r){
        lh = max(lh, height[l]);
        rh = max(rh, height[r]);
        if(lh>=rh){
            ans += rh - height[r--];
        }else{
            ans += lh - height[l++];
        }
    }
    cout << ans;
}
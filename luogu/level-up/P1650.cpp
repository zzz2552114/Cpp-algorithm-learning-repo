#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> tj(n + 1);
    vector<int> king(n + 1);
    for (int i = 1; i <= n;i++) cin >> tj[i];
    for (int i = 1; i <= n;i++) cin >> king[i];
    sort(tj.begin() + 1, tj.end(),greater<int>());
    sort(king.begin() + 1, king.end(), greater<int>());
    int cnt = 0;
    for (int i = 1,j = 1,ed = n,e = n; i <= e;i++){
        if(king[i]<tj[j]){
            cnt+=200;
            if(j<ed) j++;
        }
        else if (king[i] > tj[j]){
            cnt -= 200;
            ed--;
        }
        else{
            while(tj[ed]>king[e]){
                e--;
                ed--;
                cnt+=200;
            }
            if(tj[ed]<=king[e]){
                if(tj[ed]<king[i]) cnt -= 200;
                ed--;
            }
            // 相等的时候怎么办？
        }
    }
    cout << cnt;
}
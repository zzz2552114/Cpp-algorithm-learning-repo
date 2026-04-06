// 方法2，单调栈
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }

    stack<int> stk;
    stk.emplace(arr[0]);
    for (int j = 1; j < n;j++){
        if(arr[j]<=arr[stk.top()]){
            stk.push(j);
            continue;
        }
        while(arr[j]> arr[stk.top()]){
            int tp = arr[stk.top()];
            stk.pop();
            if(stk.empty()){
                stk.emplace(j);
                continue;
            }
            else{
                ans += (j - stk.top() - 1) * (min(arr[j],arr[stk.top()]) - tp);
            }
        }
        stk.emplace(j);
    }
    cout << ans << endl;
}
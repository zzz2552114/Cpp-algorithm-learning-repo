#include<bits/stdc++.h>
using namespace std;
int arr[1000010][2];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> arr[i][0] >> arr[i][1];
    stack<int> lg, rg;
    vector<int> lv(n + 1), rv(n + 1);
    for (int i = 1; i <= n;i++){
        while(!lg.empty() && arr[lg.top()][0] <= arr[i][0]) lg.pop();
        if(lg.empty()) lv[i] = -1;
        else lv[i] = lg.top();
        lg.push(i);

        while(!rg.empty() && arr[i][0]>arr[rg.top()][0]){
            rv[rg.top()] = i;
            rg.pop();
        }
        rg.push(i);
    }
    while(!rg.empty()){
        rv[rg.top()] = -1;
        rg.pop();
    }
    vector<int> temp(n + 1, 0);
    for (int i = 1; i <= n;i++){
        if(lv[i]==-1)
            continue;
        temp[lv[i]] += arr[i][1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (rv[i] == -1)
            continue;
        temp[rv[i]] += arr[i][1];
    }
    int ans = temp[1];
    for (int i = 1; i <= n;i++){
        ans = max(ans, temp[i]);
    }
    cout << ans;
}
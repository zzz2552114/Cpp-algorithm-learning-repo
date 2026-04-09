#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e4 + 10;
int n, t,arr[maxN];

bool check(int mid){
    int i = 0;
    priority_queue<int,vector<int>,greater<int>> q;
    for (; i < mid;i++){
        q.emplace(arr[i]);
    }
    for (; i < n;i++){
        int newtime = q.top() + arr[i];
        q.pop();
        q.emplace(newtime);
    }
    for (int j = 0; j < mid - 1;j++){
        q.pop();
    }
    return q.top() <= t;
}
int main(){
    cin>>n>>t;
    for (int i = 0;i<n;i++){
        cin >> arr[i];
    }
    int l = 0, r = n;
    while(l<r){
        int mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    cout << l << endl;
}
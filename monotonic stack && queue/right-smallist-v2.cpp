#include <bits/stdc++.h>
using namespace std;
int arr[20];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<int> ans(n+1);
    stack<int> mos;
    for (int i = 1; i <= n; i++)
    {
        while(!mos.empty() && arr[mos.top()]>arr[i]){
            ans[mos.top()] = i;
            mos.pop();
        }
        mos.push(i);
    }
    while(!mos.empty()){
        ans[mos.top()] = -1;
        mos.pop();
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}
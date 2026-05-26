#include <bits/stdc++.h>
using namespace std;
int arr[20];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans;
    stack<int> mos;
    for (int i = 1; i <= n; i++)
    {
        while(!mos.empty() && arr[mos.top()]>=arr[i]){
            mos.pop();
        }
        if(mos.empty())
            ans.push_back(-1);
        else
            ans.push_back(mos.top());
        mos.push(i);
    }
    for (int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << ' ';
}
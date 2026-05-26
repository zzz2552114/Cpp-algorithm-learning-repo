#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int arr[2000010];
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> arr[i];
    vector<int> ans(n+1);
    ans[1] = 0;
    deque<int> q;
    q.push_back(1);
    for (int i = 2; i <= n;i++){
        while(!q.empty() && i-q.front()>m) q.pop_front();
        ans[i] = arr[q.front()];
        while(!q.empty() && arr[q.back()]>=arr[i])
            q.pop_back();
        q.push_back(i);
    }
    for (int i = 1; i <= n;i++)
        cout << ans[i] << '\n';
}
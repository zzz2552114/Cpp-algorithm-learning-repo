#include<bits/stdc++.h>
using namespace std;
int arr[1000010],ls[1000010],rs[1000010];
stack<int> mosl, mosr;
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> arr[i];
    for (int i = 1; i <= n;i++){
        while (!mosl.empty() && arr[mosl.top()] >= arr[i]) mosl.pop();
        if (mosl.empty())
            ls[i] = 0;
        else
            ls[i] = mosl.top();
        mosl.push(i);
        // 再处理右边第一个严格小于的
        while (!mosr.empty() && arr[mosr.top()] > arr[i])
        {
            rs[mosr.top()] = i;
            mosr.pop();
        }
        mosr.push(i);
    }
    while (!mosr.empty())
    {
        rs[mosr.top()] = n+1;
        mosr.pop();
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        long long temp = (long long)arr[i] *(long long)(rs[i] - ls[i] - 1);
        ans = max(ans, temp);
    }
    cout << ans;
}
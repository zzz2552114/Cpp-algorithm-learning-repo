#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    queue<int> que;
    for (int i = 1; i <= n;i++)
    {
        que.emplace(i);
    }
    while(!que.empty()){
        cout << que.front() << ' ' << ends;
        que.pop();
        if(que.empty()){
            return 0;
        }
        int f = que.front();
        que.pop();
        que.emplace(f);
    }
}
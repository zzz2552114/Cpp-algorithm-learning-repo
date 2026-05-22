#include<bits/stdc++.h>
using namespace std;
int arr[100010];
const double inf = 1e9 + 10;
int n, s, t;
bool check(double mid){
    double prefix[100010];
    memset(prefix, 0, sizeof(prefix));
    for (int i = 1; i <= n;i++)
        prefix[i] = prefix[i - 1] + arr[i] - mid;
    deque<int> q;
    for (int i = s; i <= n;i++){
        int c = i - s;
        while (!q.empty() && prefix[q.back()] >= prefix[c]) q.pop_back();
        while(!q.empty() && i-q.front()>t) q.pop_front();
        q.push_back(c);
        if(prefix[i]-prefix[q.front()]>0) return 1;
    }
    return 0;
}

int main(){
    cin >> n >> s >> t;
    for (int i = 1; i <= n;i++) cin >> arr[i];
    double l = 0, r = 10;
    while(r-l>1e-4){
        double mid = (l + r) / 2;
        cout << l << ' ' << r << ' ' << mid <<'\n';
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.3lf",l);
}
#include<bits/stdc++.h>
using namespace std;
int len, n, m;
const int maxN = 50010;
int arr[maxN];
bool check(int mid){
    int cnt = 0;
    int pos= 0;
    for (int i = 1; i <= n + 1;i++){
        if(arr[i] - arr[pos] < mid) cnt++;
        else pos = i;
    }
    return cnt <= m; // 这里的返回值卡了我好久
    /*
        如果cnt>m,说明，我需要移走很多块石头，才能让mid<=最小距离。
        如果cnt<m，说明，我只需要移走一点石头，就能让mid<=最小距离。
        不管怎么样，mid如果增大，cnt单调增，要让mid成为最小距离所需要移走的石头就多
    */
}
int main(){
    cin >> len >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    arr[0] = 0;
    arr[n + 1] = len;
    int l = 0, r = len;
    while(l<r){
        int mid = (l + r + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout << l << endl;
}
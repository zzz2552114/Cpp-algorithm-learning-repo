#include<iostream>
#include<algorithm>
using namespace std;

struct datas
{
    int x, y;
};
bool cmp(datas a,datas b){
    return a.x < b.x;
}
datas arr[200010];
int dp[200010],temp[200010];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> arr[i].x >> arr[i].y;
    sort(arr + 1, arr + n + 1,cmp);
    // 下面要用nlogn的最长上升子序列
    dp[1] = arr[1].y;
    int pos = 2;
    for (int i = 2; i <= n;i++){
        int n = lower_bound(dp + 1, dp + pos, arr[i].y) - dp;
        if(n==pos) dp[pos++] = arr[i].y;
        else dp[n] = arr[i].y;
    }
    cout << pos-1;
}
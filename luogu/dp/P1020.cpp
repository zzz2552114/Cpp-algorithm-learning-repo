#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> arr;
int dpdown[100050], dpup[100050];
int main(){
    int k;
    while(cin >> k)
        arr.push_back(k);
    int n = (int)arr.size();
    dpdown[1] = arr[0];
    int t = 2;
    for (int i = 2; i <= n; i++)
    {
        // 下面用nlogn找最长不上升子序列
        // 下面的我传入了自定义比较器，返回第一个不大于value的位置，恰好dpdown是降序的。
        auto pos = lower_bound(dpdown + 1, dpdown + t, arr[i-1], greater<int>());
        int p = pos - dpdown;
        if(p!=t && dpdown[p] == arr[i-1]){
            while(dpdown[++p]==arr[i-1])
                continue;
            dpdown[p] = arr[i-1];
            t = max(t, p+1);
        } 
        else if(p!=t) dpdown[p] = arr[i-1];
        else dpdown[t++] = arr[i-1]; 
    }
    cout << t - 1 << '\n';
    dpup[1] = arr[0];
    int x = 2;
    for (int i = 2; i <= n;i++){
        // 下面用nlogn找严格上升子序列
        int p = lower_bound(dpup + 1, dpup + x, arr[i-1]) - dpup;
        if(p == x) dpup[x++] = arr[i-1];
        else dpup[p] = arr[i-1];
    }
    cout << x - 1;
}
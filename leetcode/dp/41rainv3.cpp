// 方法3，动态规划
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans = 0;
    cin >>n;
    int arrl[n];
    int arrr[n];
    int arr[n];

    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    arrl[0] = arr[0];
    arrr[n - 1] = arr[n - 1];
    for (int i = 1; i < n;i++){
        arrl[i] = max(arr[i], arrl[i - 1]);
        arrr[n - i - 1] = max(arr[n - i - 1], arrr[n - i]);
    }
    for (int j = 0; j < n;j++){
        ans += min(arrl[j], arrr[j]) - arr[j];
    }
    cout << ans << endl;
}
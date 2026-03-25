#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    vector<int> search(q);
    for (int i = 0; i < q;i++){
        cin >> search[i];
    }
    for (int i = 0; i < q;i++){
        int count;
        count = upper_bound(arr.begin(), arr.end(), search[i]) - lower_bound(arr.begin(), arr.end(), search[i]);
        cout << search[i] << ' ' << count <<'\n';
    }
    cout << endl;
    // 一遍过，爽！！！！！！！
}
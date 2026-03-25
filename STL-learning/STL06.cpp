#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    set<long long> st(arr.begin(),arr.end());
    vector<long long> search(q);
    for (int i = 0; i < q;i++){
        cin >> search[i];
    }
    for (long long x:search){
        if(st.count(x)){
                cout << "Yes" << '\n';
        }else{
                cout << "No" << '\n';
        }
    }
    cout << endl;
}

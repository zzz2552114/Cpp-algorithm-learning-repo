#include<bits/stdc++.h>
using namespace std;
int arr[20];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
    }
    vector<int> ans;
    for (int i = 1; i <= n;i++){
        int temp = arr[i];
        bool found = 0;
        for (int j = i - 1; j >= 1;j--){
            if(arr[j]<temp){
                ans.push_back(j);
                found = 1;
                break;
            }
        }
        if(!found) ans.push_back(-1);
    }
    for (int i = 0; i < (int)ans.size();i++)
        cout << ans[i] << ' ';
}
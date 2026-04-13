#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,g;
    cin >> n >> g;
    int arr[n],checked[n];
    memset(checked, 0, sizeof(checked));
    for(int i = 0;i<n;i++) cin >> arr[i];
    sort(arr, &arr[n]);
    cout << "lived" << endl;
    for (int i = 0; i < n - 2;i++){
        if(checked[i]) continue;
        cout << i << ' ' << "arr[i] = " << arr[i] << ' ';
        checked[i] = 1;
        int pos = i+1,added = 1;
        while(added<3){
            if (pos >= n) return 0;
            while(arr[pos] == arr[pos-1] || checked[pos]){
                pos++;
                if(pos>=n) return 0;
            }
            cout << "pos = " << pos << ' ';
            if(arr[pos]!=arr[i]+added) return 0;
            checked[pos] = 1;
            added++;
            pos++;
        }
        cout << endl;
    }
    cout << endl;
    cout << "good" << endl;
    return 1;
}
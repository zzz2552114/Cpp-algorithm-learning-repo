#include<iostream>
#include<algorithm>
using namespace std;
int arr[105],ra[105],la[105];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++) cin >> arr[i];
    for (int i = 1; i <= n;i++){
        for (int j = 1; j < i;j++){
            if(arr[i]>arr[j]) la[i] = max(la[i],la[j]+1);
        }
    }
    for (int i = n; i >= 1;i--){
        for (int j = n; j > i;j--)
            if(arr[i]>arr[j]) ra[i] = max(ra[i],ra[j]+1);
    }
    int maxl = 0;
    for (int i = 1; i <= n;i++){
        maxl = max(maxl, ra[i] + la[i] + 1);
    }
    cout << n - maxl;
}
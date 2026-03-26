#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n;i++){
        cin >> vec[i];
    }
    // 这里要求vec本身就是有序的
    int j = 0;
    for (int i = 1; i < n;i++){
        if(vec[i]!=vec[i-1]){
            vec[++j] = vec[i];
        }
    }
    for (int i = 0; i <= j;i++){
        cout << vec[i] << ' ';
    }
    cout << endl;
}
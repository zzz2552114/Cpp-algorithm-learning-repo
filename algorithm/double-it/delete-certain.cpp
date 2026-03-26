#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,del;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    cin >> del;
    // 思想还是，放出快指针遍历数组，慢指针维护新数组
    int j = 0;
    for (int i = 0; i < n;i++){
        if(vec[i]!=del){
            vec[j++] = vec[i];
        }
    }// 最后j会自增但是没人和它对应，所以下面就需要小于j
    for (int i = 0; i < j;i++){
        cout << vec[i] << ' ';
    }
    cout << endl;
}
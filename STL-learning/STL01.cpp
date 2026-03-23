#include <bits/stdc++.h>
using namespace std;
 int main(){
     ios::sync_with_stdio(0);
     cin.tie(0);
     int n;
     cin >> n;
     vector<int> arr(n);
     for (int i = 0; i < arr.size();i++){
         cin >> arr[i];
     }
     sort(arr.begin(), arr.end());
     for(int x:arr){
         cout << x << ' ' << ends;
     }
 }
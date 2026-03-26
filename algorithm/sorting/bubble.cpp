#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr;
    for (int i = 0;i<5;i++){
        int n;
        cin >> n;
        arr.push_back(n);
    }
    int t = arr.size();
    while (t > 1)
    {
        for (int i = 0; i < t-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
        t--;
    }
    for (int x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}
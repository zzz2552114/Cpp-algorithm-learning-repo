#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int l = 1,r = n;
    while(l<r){
        int mid = (l + r + 1) / 2;
        cout << mid <<'\n';
        fflush(stdout);
        string judge;
        cin >> judge;
        if(judge == "<") r = mid-1;
        else l = mid;
    }
    cout << "! " << l;
}

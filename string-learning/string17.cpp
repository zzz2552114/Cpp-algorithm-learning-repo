#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    int num;
    cin >> num;
    cout << stoi(s) << '\n';
    string n = to_string(num);
    if(num < 0){
        reverse(n.begin() + 1, n.end());
    }else{
        reverse(n.begin(),n.end());
    }
    cout << stoi(n) << endl;
}
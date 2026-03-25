#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    map<char, int> mp;
    unordered_set<char> unst;
    vector<char> vec;
    for(char x:s){
        mp[x]++;
    }
    for (auto it = s.rbegin(); it != s.rend();it++){
        if(unst.count(*it)){
            unst.erase(*it);
        }
        unst.insert(*it);
    }
        for (auto &ele : mp)
        {
            cout << ele.first << ":" << ele.second << '\n';
        }
        for (auto &ele:unst){
            cout << ele;
        }
        cout << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    // 想法：用find分割，提取出来放到vector里，然后导入到multimap里
    // omg原来cin可以自动分割空格？
    string word;
    map<string, int> mp;
    while(cin >> word){
        mp[word]++;
    }
    for (auto &x:mp){
        cout << x.first << ' ' << x.second << '\n';
    }
    cout << endl;
}
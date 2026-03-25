// 想法：用find分割，提取出来放到map里
// 在锻炼map的++属性，映射！！
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    // 复习双指针法分割
    int pos = 0;
    map<string, int> mp;
    while(s.find(' ',pos) != string::npos){
        string word = s.substr(pos, s.find(' ', pos) - pos);
        mp[word]++;
        pos = s.find(' ', pos) + 1;
    }
    for(auto& x:mp){
        cout << x.first << ' ' << x.second << '\n';
    }
}

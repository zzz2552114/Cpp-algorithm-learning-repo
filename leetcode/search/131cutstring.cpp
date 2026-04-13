#include<bits/stdc++.h>
using namespace std;

string s;
int n;
vector<vector<string>> ans;
vector<string> temp;
bool isturn(int pos,int i){
    if(pos>=i) return true;
    if(s[pos]!=s[i]) return 0;
    return isturn(pos + 1, i - 1);
}
void dfs(int i,int pos){ // i表示当前是字符串的第i个字符
    // 有两个选择，在i后面切一刀，以及不在i后面切一刀。
    // 如果在i后面切一刀，需要保证这一刀和上一刀前面是回文，所以还需要补一下上一刀的下标
    if(i==n-1){
        if(isturn(pos+1,i)) {
            temp.push_back(s.substr(pos + 1, i - pos));
            ans.push_back(temp);
            temp.pop_back();
        }
        return;
    } 
    if(isturn(pos+1,i)){
        temp.push_back(s.substr(pos+1,i-pos));
        dfs(i+1,i);
        temp.pop_back();
    }
    dfs(i+1,pos);
}
int main(){
    getline(cin, s);
    n = (int)s.size();
    dfs(0, -1);
    for (int i = 0;i<(int)ans.size();i++){
        for (int j = 0;j<(int)ans[i].size();j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}
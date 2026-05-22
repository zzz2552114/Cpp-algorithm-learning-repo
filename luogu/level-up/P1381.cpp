#include<bits/stdc++.h>
using namespace std;

string arr[1005],txt[100010];
unordered_set<string> st,uni;
unordered_map<string, int> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 1;i<=n;i++) {
        string s;
        getline(cin, s);
        arr[i] = s;
        st.insert(s);
    }
    int m;
    cin >> m;
    cin.ignore();
    for (int i = 1; i <= m;i++){
        string s;
        getline(cin, s);
        txt[i] = s;
    }
    int cnt = 0;
    deque<int> pos;
    for (int i = 1; i <= m;i++){
        if(st.count(txt[i])){
            pos.push_back(i);
            if(!uni.count(txt[i])){
                uni.insert(txt[i]);
                cnt++;
            }
        }
    }
    int p = (int)pos.size();
    int ans = 1e9;
    for (int i = 0,j = 0; j < p;j++){
        string c = txt[pos[j]];
        mp[c]++;
        int len = (int)mp.size();
        if(len < cnt) continue;
        while(i<p && mp[txt[pos[i]]]>1){
            mp[txt[pos[i]]]--;
            i++;
        }
        ans = min(ans, pos[j] - pos[i] + 1);
    }
    if(cnt==0)
        cout << 0 << '\n'
             << 0;
    else cout << cnt <<'\n' << ans;
}
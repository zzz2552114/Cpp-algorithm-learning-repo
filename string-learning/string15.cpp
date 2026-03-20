#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 先想思路：多轮循环直到找不到，消消乐
    string s;
    string oldsub;
    string newsub;
    getline(cin,s);
    getline(cin,oldsub);
    getline(cin,newsub);

    if(oldsub.empty()){
        cout << s << endl;
        return 0;
    }

    size_t pos = 0;
    size_t nextpos;
    size_t oldlen = oldsub.size();
    int i = 0;
    while ((nextpos = s.find(oldsub, pos)) != string::npos && i<10){
        while((nextpos = s.find(oldsub,pos)) != string::npos){
            s.replace(nextpos, oldlen, newsub);
            pos = nextpos + newsub.size();
        }
        pos = 0;
        i++;
    }
    cout << s << endl;
}
// ababab old:ab new:ba -> bababa -> bbabaa -> bbbaaa
// abab old:ab new:abc 无限循环，所以加入指标i限制10次
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int k;
    cin >> s >> k;
    int pos = 0;
    int size = (int)s.size();

    while(size - pos >= k ){
        reverse(s.begin()+pos, s.begin() + pos + k);
        pos += 2 * k;
    }
    if (s.size()>pos){
        reverse(s.begin() + pos, s.end());
    }
    cout << s << endl;
}
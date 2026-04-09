#include<bits/stdc++.h>
using namespace std;
int main(){
    int pos = 0, f = 0, slow = 0,cntspace = 0;
    string pattern,s;
    unordered_map<char, string> s2p;
    unordered_map<string, char> p2s;
    getline(cin,pattern);
    getline(cin, s);
    while (pos < (int)pattern.size())
    {
        for (; f <= (int)s.size(); f++)
        {
            if (s[f] == ' ' || f == (int)s.size())
            {
                cntspace++;
                string subs = s.substr(slow, f - slow);
                cout << subs << ' ' << pattern[pos] << ' ';

                if(p2s.count(subs)){
                    if(p2s[subs] != pattern[pos])
                        cout << "NO" << endl;
                    else
                        cout << "YES" << endl;
                }
                else{
                    p2s[subs] = pattern[pos];
                    cout << "Add" << endl;
                }

                if (s2p.count(pattern[pos]))
                {
                    if (s2p[pattern[pos]] != subs)
                        cout << "NO" << endl;
                    else
                        cout << "YES" << endl;
                }
                else{
                    s2p[pattern[pos]] = subs;
                    cout << "Add" << endl;
                }
                f++;
                slow = f;
                break;
            }
        }
        pos++;
    }
    if(cntspace == (int)pattern.size() && f == (int)s.size())
        cout << "length correct" << endl;
    else
        cout << "length wrong" << endl;
}
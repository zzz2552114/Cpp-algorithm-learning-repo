#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string t;
    getline(cin, s);
    getline(cin, t);
    if (s.find(t) == string::npos)
    {
        cout << "Not found" << endl;
        return 1;
    }
    else
    {
        cout << "基础要求" << endl;
        cout << s.find(t) << endl;
        cout << t << endl;
        // bool flag = (t == s.substr(s.find(t), t.length()));
        // cout << flag << endl;

        cout << "进阶要求" << endl;
        for (int i = 0; i < s.length(); i++)
        {
            if (s.find(t, i) != string::npos)
            {
                cout << s.find(t, i) << endl;
                i = s.find(t, i);
            }
            else
            {
                continue;
            }
        }
    }
}
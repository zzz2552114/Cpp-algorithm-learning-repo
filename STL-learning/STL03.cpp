#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    stack<char> stk;
    for (char x : s)
    {
        if (x == '(')
        {
            stk.emplace(x);
        }
        else
        {
            if (stk.empty())
            {
                cout << "No" << endl;
                return 0;
            }
            stk.pop();
        }
    }
    if (stk.empty())
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    int up = 0;
    int low = 0;
    int num = 0;
    for (char x : s)
    {
        if (islower(x))
        {
            low += 1;
        }
        else if (isupper(x))
        {
            up += 1;
        }
        else
        {
            num += 1;
        }
    }
    cout << up << endl
         << low << endl
         << num << endl;
}
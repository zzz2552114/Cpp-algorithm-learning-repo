#include <bits/stdc++.h>
using namespace std;
bool cmp(string &a, string &b)
{
    if (a.size() == b.size())
    {
        return a < b;
    }
    return a.size() < b.size();
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        arr.push_back(t);
    }
    cout << "[×ÖµäÐòÅÅÐò]" << endl;
    sort(arr.begin(), arr.end());
    for (string x : arr)
    {
        cout << x << '\n';
    }
    cout << "[³¤¶ÈÓÅÏÈÅÅÐò]" << endl;
    sort(arr.begin(), arr.end(), cmp);
    for (string x : arr)
    {
        cout << x << '\n';
    }
}
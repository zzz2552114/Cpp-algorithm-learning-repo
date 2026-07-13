#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vecveci;
typedef vector<ll> vecll;
typedef vector<vector<ll>> vecvecll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1e5 + 5;

ll t, n, a[N];
ll mn = 1e9;

bool win()
{
    if (n % 2)
        return true;
    ll num = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > mn)
            num++;
    return num % 2;
}

void solve()
{
    scanf("%lld", &t);
    while (t--)
    {
        mn = 1e9;
        scanf("%lld", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
            mn = min(mn, a[i]);
        }
        if (win())
            printf("First\n");
        else
            printf("Second\n");
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    solve();
    return 0;
}

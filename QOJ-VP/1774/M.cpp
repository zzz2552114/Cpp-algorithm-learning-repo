#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vecveci;
typedef vector<ll> vecll;
typedef vector<vector<ll>> vecvecll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mapii;
typedef map<ll, ll> mapll;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;

const int N = 1 << 17 + 5;
ll n, ans = -1e18;
vecll a(N);
ll pow2[22];

void get_pow()
{
    pow2[0] = 1;
    for (int i = 1; i < 22; i++)
    {
        pow2[i] = pow2[i - 1] << 1;
    }
}

void solve()
{
    get_pow();
    scanf("%lld", &n);
    for (int i = 1; i <= pow2[n]; i++)
    {
        scanf("%lld", &a[i]);
        ans = max(ans, a[i]);
    }
    sort(a.begin() + 1, a.begin() + 1 + pow2[n], greater<int>());
    for (ll k = 1; k <= n; k++)
    {
        for (ll i = 1; i + pow2[k - 1] <= pow2[n]; i += pow2[k])
        {
            a[i] += a[i + pow2[k - 1]];
            // for (ll i = 1; i <= pow2[n]; i++)
            //     cout << a[i] << ' ';
            // cout << endl;
        }
        ans = max(ans, a[1]);
    }
    printf("%lld\n", ans);
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    solve();
    return 0;
}

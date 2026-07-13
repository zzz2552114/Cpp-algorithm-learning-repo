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

const int N = 2e5 + 5;

ll t, n, m, k, a, il, ir;
ll bound, les, equ, mor;

bool judge(vecll a)
{
    ir = upper_bound(a.begin() + 1, a.begin() + 1 + n, m) - a.begin();
    il = lower_bound(a.begin() + 1, a.begin() + 1 + n, m) - a.begin() - 1;
    les = il;
    equ = ir - il - 1;
    mor = n + 1 - ir;
    if (k % 2)
        return equ > 0 && 1 + min(n - 1, 2 * min(equ + mor - 1, equ + les - 1)) >= k;
    if (equ <= 1)
    {
        while (il >= 1 && ir <= n)
        {
            if (a[il] + a[ir] > 2 * m)
                il--;
            else if (a[il] + a[ir] < 2 * m)
                ir++;
            else
                break;
        }
        if (il == 0 || ir == n + 1)
            return false;
        bound = min(il, n + 1 - ir);
        return 2 * bound >= k;
    }
    else
    {
        return 2 + min(2 * min(les + equ - 2, mor + equ - 2), n - 2) >= k;
    }
}

void solve()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld%lld", &n, &k, &m);
        vecll a(n + 5);
        for (ll i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
        }
        sort(a.begin() + 1, a.begin() + 1 + n);
        if (judge(a))
            printf("TAK\n");
        else
            printf("NIE\n");
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int s = 0, f = 1;
    int tot = arr[0];
    while (f < n || s < f)
    {
        if (f == n && tot < k)
        {
            ans += f - s;
            s++;
        }
        else if (tot >= k)
        {
            ans += f - s - 1;
            tot /= arr[s++];
        }
        else if (tot < k)
        {
            tot *= arr[f++];
        }
    }
    cout << ans << endl;
}
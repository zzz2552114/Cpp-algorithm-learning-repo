#include <iostream>
using namespace std;
int n, m;
int arr[105], vis[105];
int p = 0;
bool flag = 0;
void dfs(int d)
{
    if (d > n)
    {
        p++;
        if (p == m)
            flag = 1;
        return;
    }
    for (int j = 1; j <= n; j++)
    {

        if (!vis[j])
        {
            vis[j] = 1;
            arr[d] = j;
            dfs(d + 1);
            if (flag)
                return;
            vis[j] = 0;
        }
    }
}
int main()
{
    cin >> n >> m;
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << arr[i] << ' ';
}
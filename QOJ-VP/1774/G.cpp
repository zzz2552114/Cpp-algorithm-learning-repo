#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int N = 55;

int n;
int board[N][N];



int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>board[i][j];
        }
    }
    int ans=-1e5;
    for(int r=1;r<=n;r++)
    {   
        int rowmin = 1e5;
        for(int c = 1;c<=n;c++){
            rowmin = min(rowmin,board[r][c]);
        }
        ans = max(ans,rowmin);
    }
    cout << ans;
    return 0;
}

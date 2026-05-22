#include <bits/stdc++.h>
using namespace std;

// __int128输出函数
void print(__int128 x)
{
    if (x == 0)
        return;
    print(x / 10);
    putchar(x % 10 + '0');
}

int main()
{
    int n, m;
    cin >> n >> m;

    // 预处理2的幂次，pow2[i] = 2^i
    __int128 pow2[85];
    pow2[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        pow2[i] = pow2[i - 1] * 2;
    }

    __int128 ans = 0;
    int arr[85];

    // 对每一行单独计算，最后累加
    for (int row = 1; row <= n; row++)
    {
        for (int i = 1; i <= m; i++)
        {
            cin >> arr[i];
        }

        // dp[i][j] = 第i天结束，从左边取了j个，从右边取了(i-j)个，最大得分
        __int128 dp[85][85] = {0};

        for (int i = 1; i <= m; i++)
        { // 第i天
            for (int j = 0; j <= i; j++)
            { // 左边取了j个
                if (j == 0)
                {
                    // 全从右边取：第i天取右边第i个
                    dp[i][0] = dp[i - 1][0] + pow2[i] * arr[m - i + 1];
                }
                else if (j == i)
                {
                    // 全从左边取：第i天取左边第i个
                    dp[i][i] = dp[i - 1][i - 1] + pow2[i] * arr[i];
                }
                else
                {

                    dp[i][j] = max(
                        dp[i - 1][j - 1] + pow2[i] * arr[j],
                        dp[i - 1][j] + pow2[i] * arr[m - (i - j) + 1]);
                }
            }
        }

        // 第m天取完所有，取所有可能的j的最大值
        __int128 row_max = 0;
        for (int j = 0; j <= m; j++)
        {
            row_max = max(row_max, dp[m][j]);
        }

        ans += row_max;
    }

    if (ans == 0)
        cout << 0;
    else
        print(ans);

    return 0;
}
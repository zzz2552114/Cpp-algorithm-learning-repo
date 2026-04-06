#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countDigitOne(int n)
    {
        int dig = 0, ans = 0;
        int m = n;
        while (m > 0)
        {
            m /= 10;
            dig++;
        }
        if (!dig)
            return 0;
        long long base = 1;
        for (int j = 0; j < dig - 1; j++)
        {
            base *= 10;
        }
        int q = n;
        for (int i = dig - 1; i >= 0; i--)
        {
            long long pos = q / base;
            if (!pos)
            {
                ans += base * (n / (base * 10));
            }
            else if (pos != 1)
            {
                ans += base * (n / (base * 10) + 1);
                q %= base;
            }
            else
            {
                q -= base;
                ans += q + 1;
                ans += base * (n / (base * 10));
            }
            base /= 10;
        }
        return ans;
    }
};
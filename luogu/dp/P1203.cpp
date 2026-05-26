#include<bits/stdc++.h>
using namespace std;
int dp1[710], dp2[710];
int main(){
    int n;
    cin >> n;
    int k = n;
    string s;
    cin >> s;
    s += s;
    n *= 2;
    dp1[0] = 1;
    int temp;
    if(s[0]!='w')
        temp = 0;
    else
        temp = -1;
    for (int i = 1; i < n;i++){
        if(s[i]=='w')
            dp1[i] = dp1[i - 1] + 1;
        else{
            if(s[i-1]=='w'){
                if(temp<0) dp1[i] = i+1;
                else{
                    if(s[i]==s[temp])
                        dp1[i] = dp1[temp] + i - temp;
                    else
                        dp1[i] = i - temp;
                }
            }
            else if(s[i-1]==s[i])
                dp1[i] = dp1[i - 1] + 1;
            else
                dp1[i] = 1;
            temp = i;
        }
    }
    dp2[n - 1] = 1;
    if(s[n-1]=='w')
        temp = n;
    else
        temp = n - 1;
    for (int i = n-2; i >= 0 ; i--)
    {
        if (s[i] == 'w')
            dp2[i] = dp2[i + 1] + 1;
        else
        {
            if (s[i + 1] == 'w')
            {
                if (temp >= n)
                    dp2[i] = n-i;
                else
                {
                    if (s[i] == s[temp])
                        dp2[i] = dp2[temp] + temp - i;
                    else
                        dp2[i] = temp - i;
                }
            }
            else if (s[i + 1] == s[i])
                dp2[i] = dp2[i + 1] + 1;
            else
                dp2[i] = 1;
            temp = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < n-1;i++){
        ans = max(ans, dp1[i] + dp2[i + 1]);
    }
    cout << min(ans,k);
}
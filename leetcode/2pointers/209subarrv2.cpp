#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int s = 0, f = 0, sum = 0, ans = (int)nums.size()+1;
        while (f <= (int)nums.size())
        {
            if (sum >= target)
            {
                ans = min(ans, f - s);
                sum -= nums[s++];
            }
            else
            {
                if (f < (int)nums.size())
                    sum += nums[f++];
                else
                    break;
            }
        }
        if (ans > (int)nums.size())
            return 0;
        return ans;
    }
};
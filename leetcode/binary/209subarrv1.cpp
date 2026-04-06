#include<bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool check(vector<int> &nums, int t, int target)
    {
        int s = 0, f = t, sum = 0;
        for (int i = 0; i < t; i++)
        {
            sum += nums[i];
        }
        if (sum >= target)
            return true;
        while (f < (int)nums.size())
        {
            sum += nums[f++];
            sum -= nums[s++];
            if (sum >= target)
                return true;
        }
        return false;
    }

public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // 二分答案
        int n = (int)nums.size();
        int l = 0;
        if (!check(nums, n, target))
            return 0;
        while (l < n)
        {
            int mid = (l + n) / 2;
            if (check(nums, mid, target))
                n = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
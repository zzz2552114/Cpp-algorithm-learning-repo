#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = (int)height.size() - 1;
        int ans = 0;
        while (l < r)
        {
            int s = (r - l) * min(height[l], height[r]);
            ans = max(s, ans);
            if (height[l] < height[r])
            {
                do
                {
                    l++;
                } while (l < r && height[l] <= height[l - 1]);
            }
            else
            {
                do
                {
                    r--;
                } while (l < r && height[r] <= height[r + 1]);
            }
        }
        return ans;
    }
};
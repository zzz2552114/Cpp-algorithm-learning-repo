#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = (int)nums.size() - 1;
        int cut = (l + r) / 2;
        if (nums[cut] <= nums[r] && nums[cut] >= nums[0])
            return nums[0];
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] >= nums[0])
                l = mid + 1;
            else
                r = mid;
        }
        return nums[l];
    }
};
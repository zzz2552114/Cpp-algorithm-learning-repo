#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // 方法2 左右指针，但是要先排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < ((int)nums.size() - 2); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = (int)nums.size() - 1;
            int target = nums[i] * -1;
            while (l < r)
            {
                if (nums[l] + nums[r] == target)
                {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    do
                    {
                        ++l;
                    } while (l < r && nums[l] == nums[l - 1]);
                    do
                    {
                        --r;
                    } while (r > l && nums[r] == nums[r + 1]);
                }
                else if (nums[l] + nums[r] > target)
                    r--;
                else
                    l++;
            }
        }
        return ans;
    }
};
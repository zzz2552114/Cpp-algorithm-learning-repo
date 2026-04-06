#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // 方法一，哈希表
        vector<vector<int>> ans;
        unordered_set<int> globalcheck;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (globalcheck.count(nums[i]))
            {
                continue;
            }
            int target = nums[i] * -1;
            unordered_set<int> st;
            unordered_set<int> check;
            for (int j = i + 1; j < (int)nums.size(); j++)
            {
                if (globalcheck.count(nums[j]))
                {
                    continue;
                }
                if (!st.count(target - nums[j]))
                { // 如果它的共轭不在已遍历里
                    st.emplace(nums[j]);
                }
                else
                { // 如果共轭在里面
                    if (!check.count(nums[j]))
                    {
                        ans.push_back({nums[i], nums[j], -nums[j] - nums[i]}); // 找到一组答案
                        check.emplace(nums[j]);                                // 去重
                    }
                }
            }
            globalcheck.emplace(nums[i]);
        }
        return ans;
    }
};
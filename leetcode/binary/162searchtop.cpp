#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int l = 1,r = (int)nums.size()-2;
        if(nums[1]<nums[0]) return 0;
        if(nums[r]<nums[r+1]) return r+1;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid-1]>nums[mid]) r = mid-1;
            else if(nums[mid+1]>nums[mid]) l = mid+1;
            else return mid;
        }
    return l;
    }
};
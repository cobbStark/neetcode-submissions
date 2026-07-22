class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int x=binarySearch(nums, target, 0);
        int i=x, j=x;
        if(x!=-1)
        {
        while(i-1>=0 && nums[i-1]==nums[i]) --i;
        while(j<nums.size()-1 && nums[j+1]==nums[j]) ++j;
        }
        return {i, j};


        

    }
    int binarySearch(vector<int>& nums, int target, int start)
    {
        int n=nums.size();
        int l=start, h=n-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(target==nums[mid])
            return mid;
            if(target<nums[mid])
            h=mid-1;
            else
            l=mid+1;
        }
        return -1;
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0 , nums.size()-1);
    }
    int binarySearch(vector<int>& nums, int target, int low, int high)
    {
        int mid=low+(high-low)/2;
        if(low==high&& target!=nums[low])
        return -1;

        if(target==nums[mid])
        return mid;
        if(nums[mid]>=nums[low]&& (target>nums[mid]||target<nums[low]))
        return binarySearch(nums, target, mid+1, high);
        else if(nums[high]>nums[mid]&&(target>nums[high]||target<nums[mid]))
        return binarySearch(nums, target, low, mid);
        else if(target>nums[mid])
        return binarySearch(nums, target, mid+1, high);
        else
        return binarySearch(nums, target, low, mid);

    }
};

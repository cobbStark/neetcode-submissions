class Solution {
public:
    int findMin(vector<int> &nums) {
        int x=binarySearch(nums, 0, nums.size()-1);
        return x;
    }
    int binarySearch(vector<int> &nums, int low, int high)
    {
        if(low==high)
        return nums[low];

        int mid=(high+low)/2;
        int val;
        if(nums[mid]>nums[low]&&nums[high]>nums[mid])
        return nums[low];

        if(nums[mid]>nums[high])//left is sorted
        {
            return binarySearch(nums, mid+1, high);
        }
        if(nums[mid]<nums[low])
        {
            return binarySearch(nums, low, mid);
        }
    
    }
};

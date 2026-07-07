class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0, right=0;
        int sum=0;
        int min=nums.size()+1;
        while(left<=right && right!=nums.size())
        {
            sum+=nums[right];
            while(sum>=target)
            {
                if(right-left+1<min)
                min=right-left+1;

                sum-=nums[left];
                ++left;
                
            }
            
            ++right;
        }
        return min==nums.size()+1?0:min;

    }
};
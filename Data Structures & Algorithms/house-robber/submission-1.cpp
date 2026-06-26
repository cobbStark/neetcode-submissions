class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        if(nums.size()==0)
        return 0;
        if(nums.size()==1)
        return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);
        for(int i=0; i<nums.size(); i++)
        {
            if(i<2)
            continue;
            dp[i]=max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};

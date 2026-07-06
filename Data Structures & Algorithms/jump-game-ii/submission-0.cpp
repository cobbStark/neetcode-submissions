class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, n+1);
        dp[0]=0;
        for(int i=0; i<n; i++)
        {
            for(int x=1; x<=nums[i]; x++)
            if(i+x<n)
            dp[i+x]=std::min(1+dp[i], dp[i+x]);
        }
        return dp[n-1];
    }
};

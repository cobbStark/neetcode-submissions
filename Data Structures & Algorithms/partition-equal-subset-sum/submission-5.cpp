class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int& x: nums)
        sum+=x;
        if(sum%2!=0)
        return false;
        sum/=2;
        //find no of subsets whose sum=sum
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1, 0));
        dp[0][0]=1;
        for(int i=1; i<=n; i++)
        dp[i][0]=1;
        for(int i=1; i<=n; i++)
        {
            int currNum=nums[i-1];
            for(int j=1; j<=sum; j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=currNum)
                dp[i][j]=dp[i-1][j]||dp[i-1][j-currNum];
            }
        }
        return dp[n][sum];
    }
};

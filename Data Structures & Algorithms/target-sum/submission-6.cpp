class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size()==1)
        return nums[0]==abs(target);
        int sum=0;
        for(int& x: nums)
        sum+=x;
        sum-=target;
        if(sum%2!=0)
        return 0;
        sum/=2;
        cout<<sum;
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1, 0));
        for(int i=0; i<=nums.size(); i++) dp[i][0]=1;
        for(int i=1; i<=nums.size(); i++)
        {
            int currNum=nums[i-1];
            for(int j=0; j<=sum; j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=currNum)
                dp[i][j]+=dp[i-1][j-currNum];
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[nums.size()][sum];
    }
};

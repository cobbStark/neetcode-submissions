class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, amount+1));
        for(int i=0; i<=coins.size(); i++)
        dp[i][0]=0;
        for(int i=1; i<=coins.size(); i++)
        {
            int currCoin=coins[i-1];
            for(int j=0; j<=amount; j++)
            {
                if(j>=currCoin)
                dp[i][j]=std::min(1+dp[i][j-currCoin], dp[i-1][j]);
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        if(dp[coins.size()][amount]>=amount+1)
        return -1;
        return dp[coins.size()][amount];
    }
};

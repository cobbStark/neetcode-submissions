class Solution {
public:
    int maxProfit(vector<int>& prices) {
      //at a given time, 3 states: hold, rest, sell
      int n=prices.size();
      vector<vector<int>> dp(n+1, vector<int>(3, 0));
      if(n==0)
      return 0;
      dp[0][0]=-INT_MAX;
      dp[0][1]=0;
      dp[0][2]=-INT_MAX;
      for(int i=1; i<=n; i++)
      {
        int currCost=prices[i-1];
        dp[i][0]=std::max(dp[i-1][0], dp[i-1][1]-currCost);
        dp[i][1]=std::max(dp[i-1][1] , dp[i-1][2]);
        dp[i][2]=dp[i-1][0]+currCost;

        cout<<dp[i][0]<<dp[i][1]<<dp[i][2]<<endl;
      }  
      return std::max(dp[n][2], dp[n][1]);
    }
};

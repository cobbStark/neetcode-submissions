class Solution {
public:
    int numDistinct(string s, string t) {
        int s1=s.length(), t1=t.length();
        if(s1<t1)
        return 0;
        else if(s1==t1 && s!=t)
        return 0;
        vector<vector<long long>> dp(s1+1, vector<long long>(t1+1, 0));
        for(int i=0; i<=s1; i++)
        dp[i][0]=1;
        for(int i=1; i<=s1; i++)
        {
            for(int j=1; j<=t1; j++)
            {
                if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else
                dp[i][j]=dp[i-1][j];

                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[s1][t1];
    }
};

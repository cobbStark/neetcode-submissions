class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, 0));
        dp[0][0]=1;
        if(s3.length()!=s1.length()+s2.length())
        return false;
        for(int i=1; i<=s1.length(); i++)
        {
            if(s3[i-1]==s1[i-1])
            dp[i][0]=dp[i-1][0];

        }
        for(int i=1; i<=s2.length(); i++)
        {
            if(s3[i-1]==s2[i-1])
            dp[0][i]=dp[0][i-1];
        }
        
        for(int i=1; i<=s1.length(); i++)
        {
            for(int j=1; j<=s2.length(); j++)
            {
                if(s3[i+j-1]==s1[i-1]&&s3[i+j-2]==s2[j-1])
                dp[i][j]=dp[i-1][j]||dp[i][j-1];
                else if(s3[i+j-1]==s1[i-1])
                dp[i][j]=dp[i-1][j];
                else if(s3[i+j-1]==s2[j-1])
                dp[i][j]=dp[i][j-1];

                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[s1.length()][s2.length()];
    }
};

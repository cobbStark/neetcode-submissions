class Solution {
public:
    int numDecodings(string s) {    
        int n=s.length();
       vector<int> dp(n , 0);
       dp[0]=1;
       if(s[0]=='0')
       return 0;
       if(n==1)
       return 1;

        int sum=(s[1]-'0'+(10*(s[0]-'0')));
        if(s[1]-'0'!=0 && s[0]-'0'!=0)
        ++dp[1];
        if(sum>=10&&sum<=26)
        {
            dp[1]+=1;
        }
        
        
       for(int i=2; i<n; i++)
       {
        if(s[i]!='0')
        dp[i]+=dp[i-1];
        int sum=(s[i]-'0'+(10*(s[i-1]-'0')));
       if(sum>=10 && sum<=26)
       dp[i]+=dp[i-2];
       }
       return dp[n-1];
    }
};

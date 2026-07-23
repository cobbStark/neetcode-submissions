class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1, 0);
        unordered_set<string> u(wordDict.begin(), wordDict.end());
        dp[0]=1;
        for(int i=1; i<=s.length(); i++)
        {
            for(int j=0; j<i; j++)
            {
                if(dp[j]&& u.contains(s.substr(j, i-j)))
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[s.length()];

    }
};

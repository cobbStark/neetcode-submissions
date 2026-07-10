class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 1));
        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(!visited[i][j])
                dfs(matrix,dp, visited, i, j);
            }
        }
        int max=0;
        for(int i=0; i<dp.size(); i++)
        for(int j=0; j<matrix[0].size(); j++)
        max=std::max(max, dp[i][j]);
        return max;

    }
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, vector<vector<int>>& visited, int i, int j)
    {
        if(i>=0&&j>=0&&i<matrix.size()&&j<matrix[0].size()&&!visited[i][j])
        {
            visited[i][j]=1;
            int dr[]={-1, 1, 0, 0};
            int dc[]={0, 0, -1, 1};
            for(int x=0; x<4; x++)
            {
                int nr=dr[x]+i, nc=dc[x]+j;
                
                if(nr>=0 && nr<matrix.size() && nc>=0 && nc<matrix[0].size() && matrix[nr][nc]<matrix[i][j])
                {
                dfs(matrix, dp, visited, nr, nc);
                dp[i][j]=std::max(dp[i][j], 1+dp[nr][nc]);
                }
            }
        }
    }
    
};

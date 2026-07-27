class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<vector<int>> visited, string& word, int i, int j, int t)
    {
        //cout<<board[i][j]<<" "<<t<<" ";
        visited[i][j]=1;
        int n=board.size(), m=board[0].size();
        if(t==word.length()-1)
        return true;
        int dr[]={-1, 1, 0, 0};
        int dc[]={0, 0, 1, -1};
        for(int x=0; x<4; x++)
        {
            int nr=dr[x]+i;
            int nc=dc[x]+j;
            //cout<<nr<<nc<<endl;
            if(nr>=0 && nc>=0 && nr<n && nc<m && visited[nr][nc]==0 && board[nr][nc]==word[t+1])
            {
                cout<<nr<<nc<<endl;
                if(dfs(board, visited, word, nr, nc, t+1))
                return true;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(), m=board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]==word[0])
                {
                           //  cout<<board[i][j]<<" ";
                    vector<vector<int>> visited(n, vector<int>(m, 0));
                    visited[i][j]=1;
                    if(dfs(board, visited, word, i, j, 0))
                    {
                    return true;
                    }
                    for(int i=0; i<n; i++)
                    {
                        for(int j=0; j<m; j++)
                        cout<<visited[i][j];
                        cout<<endl;
                    }
                }
            }
        }
        return false;
    }
};

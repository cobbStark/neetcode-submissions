class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int rows=board.size(), cols=board[0].size();
        vector<vector<int>> change(rows, vector<int>(cols, 0));
        for(int i=0; i<rows; i++)
        {
            if(board[i][0]=='O')q.push({i, 0});
            if(board[i][cols-1]=='O') q.push({i, cols-1});
        }
        for(int j=1; j<cols-1; j++)
        {
            if(board[0][j]=='O') q.push({0, j});
            if(board[rows-1][j]=='O')  q.push({rows-1, j});
        }
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            //cout<<i<<j;
            change[i][j]=1;
            q.pop();
            int dr[]={-1, 1, 0, 0};
            int dc[]={0, 0, 1, -1};
            for(int x=0; x<4; x++)
            {
                int nr=dr[x]+i, nc=dc[x]+j;
                if(nr>=1 && nc>=1 && nr<rows-1 && nc<cols-1 && board[nr][nc]=='O' && change[nr][nc]==0 )
                q.push({nr, nc});

            }
        }
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(board[i][j]=='O'&&change[i][j]==0)
                board[i][j]='X';
            }
        }
    }
};

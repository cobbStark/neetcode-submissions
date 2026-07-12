class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==0)
                q.push({i, j, 0});
            }
        }
        while(!q.empty())
        {
            int i=q.front()[0], j=q.front()[1];
            grid[i][j]=std::min(grid[i][j], q.front()[2]);
            int dr[]={-1, 1, 0, 0};
            int dc[]={0, 0, 1, -1};
            for(int x=0; x<4; x++)
            {
                int nr=dr[x]+i, nc=dc[x]+j;
                if(nr>=0&&nc>=0&&nr<grid.size()&&nc<grid[0].size()&&grid[nr][nc]==INT_MAX)
                q.push({nr, nc, q.front()[2]+1});
            }
            q.pop();
        }
    }
};

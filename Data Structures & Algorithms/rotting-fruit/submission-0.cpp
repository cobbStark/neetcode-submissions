class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int count=0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==1)
                ++count;
                if(grid[i][j]==2)
                q.push({i, j});
            }
        }
        int minutes=0;

        while(!q.empty() && count>0)
        {
            int size=q.size();
            for(int k=0; k<size; k++)
            {
            int i=q.front().first, j=q.front().second;
            q.pop();

            int dr[]={-1, 1, 0 , 0};
            int dc[]={0, 0, 1, -1};
            for(int x=0; x<4; x++)
            {
                int nr=dr[x]+i, nc=dc[x]+j;
                if(nr>=0&&nc>=0&&nr<grid.size()&&nc<grid[0].size()&&grid[nr][nc]==1)
                {
                    grid[nr][nc]=2;
                q.push({nr, nc});
                --count;
                }
            }
            }
            ++minutes;
            
        }
        if(count!=0)
        return -1;
        return minutes;
    }
};

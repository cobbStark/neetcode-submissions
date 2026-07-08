class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]!='1')
                continue;
                ++count;
                dfs(grid, i, j);
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        int dl[]={-1, 0, 1, 0};
        int dr[]={0, 1, 0, -1};
        grid[i][j]='0';
        for(int x=0; x<4; x++)
        {
            int nl=i+dl[x], nr=j+dr[x];
            if(isValid(nl, nr, grid.size(), grid[0].size())&&grid[nl][nr]=='1')
            {
                dfs(grid, nl, nr);
            }
        }
    }
    bool isValid(int i, int j, int n, int n1)
    {
        return (i>=0 && i<n && j>=0 && j<n1);
    }

};

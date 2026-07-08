class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max=0, count;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                count=dfs(grid, i, j);
                if(count>max)
                max=count;
            }
        }
        return max;
    }
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        int count=0;
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]==1)
        {
        count+=1;
        grid[i][j]=0;
        count+=dfs(grid, i+1, j);
        count+=dfs(grid, i-1, j);
        count+=dfs(grid, i, j+1);
        count+=dfs(grid, i, j-1);
        }
        return count;
    }
};

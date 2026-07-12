class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows=heights.size(), cols=heights[0].size();
        vector<vector<int>> pacific(rows, vector<int>(cols, 0));
        vector<vector<int>> atlantic(rows, vector<int>(cols, 0));
        queue<vector<int>> p;
        queue<vector<int>> a;
        for(int i=0; i<rows; i++)
        {
            pacific[i][0]=1;
            p.push({i, 0});
            atlantic[i][cols-1]=1;
            a.push({i, cols-1});
        }
        p.push({0, cols-1});
        pacific[0][cols-1]=1;
        for(int j=1; j<cols-1; j++)
        {
            pacific[0][j]=1;
            p.push({0, j});
            atlantic[rows-1][j]=1;
            a.push({rows-1, j});
        }
        a.push({rows-1, 0});
        atlantic[rows-1][0]=1;
        while(!p.empty())
        {
            int i=p.front()[0], j=p.front()[1];
            pacific[i][j]=1;
            int dr[]={-1, 1, 0, 0};
            int dc[]={0, 0, 1, -1};
            for(int x=0; x<4; x++)
            {
                int nr=dr[x]+i, nc=dc[x]+j;
                if(nr>=0&&nc>=0&&nr<rows&&nc<cols&&pacific[nr][nc]==0 && heights[nr][nc]>=heights[i][j])
                p.push({nr, nc});
            }
            p.pop();
        }
        while(!a.empty())
        {
            int i=a.front()[0], j=a.front()[1];
            atlantic[i][j]=1;
            int dr[]={-1, 1, 0, 0};
            int dc[]={0, 0, 1, -1};
            for(int x=0; x<4; x++)
            {
                int nr=dr[x]+i, nc=dc[x]+j;
                if(nr>=0&&nc>=0&&nr<rows&&nc<cols&& atlantic[nr][nc]==0 && heights[nr][nc]>=heights[i][j])
                a.push({nr, nc});
            }
            a.pop();
        }
        vector<vector<int>> out;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                cout<<pacific[i][j]<<" ";
                if(pacific[i][j]&&atlantic[i][j])
                out.push_back({i, j});
            }
            cout<<endl;
        }
    return out;
    }
};

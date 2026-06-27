class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                if(matrix[i][j]==0)
                {
                    for(int j1=0; j1<matrix[i].size(); j1++)
                    {
                        if(matrix[i][j1]==0)
                        continue;
                        else
                        matrix[i][j1]=INT_MAX-7;
                    }
                    for(int i1=0; i1<matrix.size(); i1++)
                    {
                        if(matrix[i1][j]==0)
                        continue;
                        else
                        matrix[i1][j]=INT_MAX-7;
                    }
                }
            }
        }
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                if(matrix[i][j]==INT_MAX-7)
                matrix[i][j]=0;
            }
        }
    }
};

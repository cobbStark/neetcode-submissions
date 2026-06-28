class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i=0, j=0, i1=0, j2=matrix[0].size()-1, j1=0, i2=matrix.size()-1;
        vector<int> out;
        out.push_back(matrix[i][j]);
        for(int x=1, x1=x; x<matrix[0].size()*matrix.size(); x++, x1++)
        {
            
            if(x1==0 )
            {
                ++j;
            }
            else if(i==i1 && j>=j1 && j<j2)
            {
                ++j;
            }
            else if(i==i2 && j>j1 && j<=j2)
            {
                --j;
            }
            else if(j==j2 && i>=i1 && i<i2)
            {
                ++i;
            }
            else 
            --i;

            out.push_back(matrix[i][j]);
            if(x1+1==2*(i2-i1+j2-j1))
            {
                ++i1;
                --i2;
                ++j1;
                --j2;
                x1=-1;
            }
            
        }
        return out;
    }
};

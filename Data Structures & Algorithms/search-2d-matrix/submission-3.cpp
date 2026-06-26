class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=matrix[0].size();
        int i=0, j=l-1;
        while(i<matrix.size() && j>=0)
        {
            if(matrix[i][j]==target )
            return true;
            if(matrix[i][j]> target)
            --j;
            else 
            ++i;

        }
        return false;
    }
};

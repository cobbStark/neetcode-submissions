class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=matrix[0].size()-1;
        for(int i=0; i<matrix.size(); i++)
        {
                if(target<=matrix[i][l])
                {
                    int low=0, high=l;
                    while(low<=high)
                    {
                        int mid=low+(high-low)/2;
                        if(target==matrix[i][mid])
                        return true;
                        if(target>matrix[i][mid])
                        low=mid+1;
                        else
                        high=mid-1;
                    }
                    return false;
            
            }
        }
        return false;
    }
};

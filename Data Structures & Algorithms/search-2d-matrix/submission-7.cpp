class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0, high=matrix.size()-1;
        int row;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][matrix[0].size()-1])
            {
                row=mid;
            break;
            }
            if(target>matrix[mid][0])
            low=mid+1;
            else
            high=mid-1;
        }
        low=0;
        high=matrix[0].size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(matrix[row][mid]==target)
            return true;
            if(target<matrix[row][mid])
            high=mid-1;
            else
            low=mid+1;
        }
        return false;
    }
};

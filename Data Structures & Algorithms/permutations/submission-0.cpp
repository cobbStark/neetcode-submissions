class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> output;
        for(int& x: nums)
        {
            
            vector<int> temp;
            if(n==1)
            {    
                temp.push_back(nums[0]);
                output.push_back(temp);
                return output;
            }
            for(int& y: nums)
            {
                if(y==x)
                continue;
                temp.push_back(y);
            }
            vector<vector<int>> sub=permute(temp);
            for(vector<int>& v: sub)
            {
                v.push_back(x);
                output.push_back(v);
            }

        }
        return output;
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        vector<int> path;
        out.push_back(path);
        return backtrack(path, 0, nums, out);
        }
        vector<vector<int>>& backtrack(vector<int>& path, int i, vector<int>& nums, vector<vector<int>>& out)
        {
            for(int j=i; j<nums.size(); j++)
            {
                if(j>i&&nums[j-1]==nums[j])
                continue;
                path.push_back(nums[j]);
                out.push_back(path);
                backtrack(path, j+1, nums, out);
                path.pop_back();
            }
            return out;

        }
    
};

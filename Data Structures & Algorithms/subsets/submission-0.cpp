class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> path;
        return backtrack(path, nums, 0, out);
        
    }
    vector<vector<int>> backtrack(vector<int>& path, vector<int>& nums, int i, vector<vector<int>>& out)
    {
        if(i==nums.size())
        {
        out.push_back(path);
        return out;
        }

        backtrack(path, nums, i+1, out);
        path.push_back(nums[i]);
        backtrack(path, nums, i+1, out);
        path.pop_back();
        return out;
    }
};

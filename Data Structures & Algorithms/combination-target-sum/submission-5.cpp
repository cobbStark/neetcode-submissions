class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> out;
        vector<int> path;
        std::sort(nums.begin(), nums.end());
        return backtrack(path, 0, nums, 0, out, target);
    }
    vector<vector<int>>& backtrack(vector<int>&path, int pathSum, vector<int>& nums, int start, vector<vector<int>>& out, int target)
    {
        if(pathSum==target)
        {
            out.push_back(path);
            return out;
        }
        if(start==nums.size())
        return out;
        for(int i=start; i<nums.size(); i++)
        {
            if(nums[i]+pathSum>target)
            break;
            pathSum+=nums[i];
            path.push_back(nums[i]);
            backtrack(path, pathSum, nums, i, out, target);
            pathSum-=nums[i];
            path.pop_back();
        }
        return out;
    }
};

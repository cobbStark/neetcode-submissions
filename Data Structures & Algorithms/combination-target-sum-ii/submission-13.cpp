class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> out;
        vector<int> path;
        std::sort(candidates.begin(), candidates.end());
        return backtrack(path, 0, candidates, 0, out, target);
    }
    vector<vector<int>>& backtrack(vector<int>& path, int pathSum, vector<int>& nums, int i, vector<vector<int>>& out, int target)
    {
        if(pathSum==target)
        {
            out.push_back(path);
            return out;
        }
        if(i==nums.size())
        return out;
        
        for(int j=i; j<nums.size(); j++)
        {
            if(nums[j]+pathSum>target)
            break;
            pathSum+=nums[j];
            path.push_back(nums[j]);
            backtrack(path, pathSum, nums, j+1, out, target);
            path.pop_back();
            pathSum-=nums[j];
            while(j!=nums.size()-1&&nums[j+1]==nums[j])
            ++j;
        }
        return out;
    }
};

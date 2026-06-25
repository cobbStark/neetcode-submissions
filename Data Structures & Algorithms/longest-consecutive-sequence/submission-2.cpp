class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int max=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(i!=0 && nums[i]==nums[i-1]+1)
            continue;
            int count=0;
            for(int j=nums[i]; s.contains(j); j++) ++count;
            if(count>max)
            max=count;
            
        }
        return max;
    }
};
